#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h> 
#include <time.h>

void Pop_images(char ImgTab[10]){
    FILE *file;

    unsigned short bit_pds_faible; // Première partie de l'adresse de l'image
    unsigned short bit_pds_fort;   // Deuxième partie
    unsigned short pos_temp;       // Combinaison bit poids fort et faible
    unsigned short pos_final;      // Soustraction pos_temp - adresse où est chargé le fichier

    unsigned char pixel;
    int nb_oct_par_ligne = 0;  
    int nb_lines = 0;          

    
    file = fopen(ImgTab, "rb");

    if (file == NULL) {
        perror("Erreur d'ouverture du fichier");
        return 1;
    }

    // Déplace l'offset à la fin du fichier
    fseek(file, 0, SEEK_END);

    // Renvoie la position de l'offset et donc la taille du fichier
    size_t file_size = ftell(file);

    if (file_size == -1) {
        perror("Erreur lors de la lecture de la taille du fichier");
        fclose(file);
        return 1;
    }

    // Tableau qui va contenir le fichier
    unsigned char *fichier = (unsigned char *)malloc(file_size * sizeof(unsigned char));

    if (fichier == NULL) {
        perror("Erreur d'allocation de mémoire");
        fclose(file);
        return 1;
    }

    // Offset remis au début du fichier pour charger le fichier
    rewind(file);

    // Charger le fichier dans le tableau
    size_t res = fread(fichier, 1, file_size, file);

    if (res != file_size) {
        perror("Lecture du fichier échouée");
        free(fichier);
        fclose(file);
        return 1;
    }

    
    fclose(file);

    // Nombre d'images +1 qui correspond au premier fichier
    unsigned char nb_image = fichier[0];
    printf("nb image:  %u\n", nb_image);

    // Initialisation de SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Erreur d'initialisation de SDL: %s\n", SDL_GetError());
        free(fichier);
        return 1;
    }

   
    // Pour sauvegarder l'image
    SDL_Surface *screenshot = NULL;

    // lire les images
    for (int i = 0; i < nb_image; i++) {

        printf("image num  %u \n", i);
        bit_pds_faible = fichier[2 * i + 1];
        bit_pds_fort = fichier[2 * i + 2];

        printf("bits de poids faible: %02X\n", bit_pds_faible);
        printf("bits de poids fort:  %02X\n", bit_pds_fort);

        pos_temp = (bit_pds_fort << 8) | bit_pds_faible; // Combiner les 2 adresses
        printf("position temp avant soustraction: %02X\n", pos_temp);

        pos_final = pos_temp - 0x6000;
        printf("pos final en hexa %04X\n", pos_final);
        printf("pos final en décimal %u\n", pos_final);

        // Lire nombre d'octets par ligne et nombre de lignes
        nb_oct_par_ligne = fichier[pos_final];
        nb_lines = fichier[pos_final + 1];
        printf("nb_oct_par_ligne %u\n", nb_oct_par_ligne);
        printf("nb_lines %u\n", nb_lines);

             // Créer une fenêtre SDL
    SDL_Window *window = SDL_CreateWindow("Affichage Image avec SDL",
                                          SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                          nb_oct_par_ligne*7, nb_lines, SDL_WINDOW_SHOWN);
     if (window == NULL) {
        printf("Erreur  %s\n", SDL_GetError());
        SDL_Quit();
        free(fichier);
        return 1;
     }

     // Créer un renderer pour dessiner dans la fenêtre 
     SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
     if (renderer == NULL) {
        printf("Erreur  %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        free(fichier);
        return 1;
     }
 

        unsigned short pos_ligne = pos_final + 2 + ((nb_lines - 1) * nb_oct_par_ligne);

        // Créer une SDL_Surface pour y dessiner l'image
        screenshot = SDL_CreateRGBSurface(0, nb_oct_par_ligne*7, nb_lines, 32, 0, 0, 0, 0);
        if (!screenshot) {
            printf("Erreur  %s\n", SDL_GetError());
            SDL_DestroyRenderer(renderer);
            SDL_DestroyWindow(window);
            SDL_Quit();
            free(fichier);
            return 1;
        }

        int y=0;// pour la coordonnée y de chaque pixel, +1 à la fin de chaque ligne
        // Pour chaque ligne de l'image
        for (int line_num = nb_lines - 1; line_num >= 0; line_num--) {
            int x=0;
            // Pour chaque octet de la ligne
            for (int byte = 0; byte < nb_oct_par_ligne; byte++) {
                pixel = fichier[pos_ligne];
                pos_ligne = pos_ligne + 1;

                // Pour chaque bit dans l'octet
                for (int bit = 0; bit < 7; bit++) {
                    if (pixel & (1 << (bit))) {
                        // Dessiner le pixel sur la surface (blanc pour pixel allumé )
                        SDL_Rect rect = { x, y, 1, 1 };
                        SDL_FillRect(screenshot, &rect, SDL_MapRGB(screenshot->format, 255, 255, 255));
                        x++;
                    } else {
                        // Dessiner le pixel éteint (noir)
                        SDL_Rect rect = { x, y, 1, 1 };
                        SDL_FillRect(screenshot, &rect, SDL_MapRGB(screenshot->format, 0, 0, 0));
                        x++;
                    }
                }
            }

            pos_ligne = pos_ligne - (2 * nb_oct_par_ligne);
            y++;
        }

        // Sauvegarder la surface en JPEG
        char image_name[50];
        sprintf(image_name, "output_image%d.jpg", i);

        if (IMG_SaveJPG(screenshot,image_name, 1000) != 0) {
            printf("Erreur lors de l'enregistrement en JPEG: %s\n", SDL_GetError());
        } else {
            printf("Image sauvegardée en JPEG\n");
        }

        // Libérer la surface
        SDL_FreeSurface(screenshot);

        // Mettre à jour l'affichage à l'écran
        SDL_RenderPresent(renderer);

        // Attendre quelques secondes pour afficher l'image
        SDL_Delay(20);

        
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
    }

    

    
    SDL_Quit();
    free(fichier);





}

int main() {
   
    Pop_images("IMG.BGTAB1.DUN");
    return 0;
}
//gcc -o s  sdl.c -lSDL2 -lSDL2_image