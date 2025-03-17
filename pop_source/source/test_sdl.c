//
// Created by margo on 17/03/2025.
//

#include "../utils/global.h"

int main() {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = SDL_CreateWindow("Test DrawBack", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    loadBgTables(renderer);  // Charger les textures des backgrounds

    // Simuler un remplissage de bgX, bgY et bgIMG
    bgX[0] = 1;
    bgX[1] = 10; bgY[1] = 5; bgIMG[1] = 3; 

    int running = 1;
    SDL_Event event;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) running = 0;
        }

        SDL_RenderClear(renderer);
        DRAWALL(renderer);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
