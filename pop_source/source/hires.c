//
// Created by margo on 11/03/2025.
//

#include "../utils/global.h"

void fastlay(SDL_Renderer *renderer) {
    if (!IMAGE_TEXTURE) return;  // Si aucune image, ne rien faire

    SDL_Rect dstRect = {XCO * 4, YCO * 2, 32, 32}; // Position et taille
    SDL_RenderCopy(renderer, IMAGE_TEXTURE, NULL, &dstRect);
}
