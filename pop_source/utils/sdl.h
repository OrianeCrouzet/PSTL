//
// Created by OrianeCrouzet on 11/03/2025.
//

#include "global.h"

#ifndef SDL_H
#define SDL_H

#define MAX_IMAGES 128

// Tableau des textures chargées
extern SDL_Texture *bgTable1[MAX_IMAGES];
extern SDL_Texture *bgTable2[MAX_IMAGES];

// Fonction pour charger les images
void loadBgTables(SDL_Renderer *renderer);

// Nouvelle variable pour stocker la texture de l’image chargée avec SDL (associée à IMAGE)
extern SDL_Texture *IMAGE_TEXTURE;

#endif //SDL_H
