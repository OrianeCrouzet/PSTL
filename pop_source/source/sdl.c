//
// Created by OrianeCrouzet on 11/03/2025.
//

#include "../utils/global.h"

void loadBgTables(SDL_Renderer *renderer) {
    char path[64];

    // Charger les images dans bgTable1 (banque 1)
    for (int i = 0; i < MAX_IMAGES; i++) {
        snprintf(path, sizeof(path), "images/BGTAB1/output_image%d.jpg", i);
        bgTable1[i] = IMG_LoadTexture(renderer, path);
        if (!bgTable1[i]) {
            printf("Erreur chargement %s : %s\n", path, IMG_GetError());
        }
    }

    // Charger les images dans bgTable2 (banque 2)
    for (int i = 0; i < MAX_IMAGES; i++) {
        snprintf(path, sizeof(path), "images/BGTAB2/output_image%d.jpg", i);
        bgTable2[i] = IMG_LoadTexture(renderer, path);
        if (!bgTable2[i]) {
            printf("Erreur chargement %s : %s\n", path, IMG_GetError());
        }
    }
}