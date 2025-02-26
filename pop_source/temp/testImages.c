//
// Created by margo on 03/02/2025.
//

#include "testImages.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>

#define MAX_IMG 1

void remove_old_images() {
    DIR *dir = opendir(".");
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strncmp(entry->d_name, "image_", 6) == 0 && strstr(entry->d_name, ".pgm")) {
            unlink(entry->d_name);
        }
    }
    closedir(dir);
}

void extract_images(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }

    remove_old_images();

    uint8_t num_images;
    fread(&num_images, sizeof(uint8_t), 1, file);
    printf("Nombre d'images: %d\n", num_images);

    if (num_images == 0) {
        printf("Aucune image détectée.\n");
        fclose(file);
        return;
    }

    uint16_t *image_addresses = malloc((num_images + 1) * sizeof(uint16_t));
    if (!image_addresses) {
        perror("Erreur d'allocation mémoire pour les adresses des images");
        fclose(file);
        return;
    }

    for (int i = 0; i <= num_images; i++) {  // Lire une adresse supplémentaire pour le premier byte libre
        uint8_t low_byte, high_byte;
        fread(&low_byte, sizeof(uint8_t), 1, file);
        fread(&high_byte, sizeof(uint8_t), 1, file);
        image_addresses[i] = (high_byte << 8) | low_byte;
    }

    for (int i = 0; i < num_images; i++) {
        fseek(file, image_addresses[i], SEEK_SET);
        if (fseek(file, image_addresses[i], SEEK_SET) != 0) {
            perror("Erreur avec fseek");
            continue;
        }

        uint8_t width, height;
        fread(&width, sizeof(uint8_t), 1, file);
        fread(&height, sizeof(uint8_t), 1, file);
        printf("Image %d - Adresse: 0x%04X, Dimensions: %dx%d\n", i, image_addresses[i], width, height);

        if (width == 0 || height == 0 || width > 255 || height > 255) {
            printf("Erreur: Dimensions invalides pour l'image %d (%dx%d)\n", i, width, height);
            continue;
        }

        /*
        uint8_t *pixel_data = malloc(width * height);
        if (!pixel_data) {
            perror("Erreur d'allocation mémoire pour les pixels");
            continue;
        }
        fread(pixel_data, sizeof(uint8_t), width * height, file);

        printf("Premiers pixels : ");
        for (int j = 0; j < 16 && j < width * height; j++) {
            printf("%02X ", pixel_data[j]);
        }
        printf("\n");

        char output_filename[50];
        sprintf(output_filename, "image_%d.pgm", i);
        FILE *output = fopen(output_filename, "w");
        if (!output) {
            perror("Erreur d'écriture du fichier PGM");
            free(pixel_data);
            continue;
        }

        fprintf(output, "P2\n%d %d\n255\n", width, height);
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                fprintf(output, "%d ", pixel_data[(height - 1 - y) * width + x]);
            }
            fprintf(output, "\n");
        }

        fclose(output);
        free(pixel_data);
 */
    }

    free(image_addresses);
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Utilisation : %s <fichier binaire>\n", argv[0]);
        return 1;
    }

    extract_images(argv[1]);
    return 0;
}
