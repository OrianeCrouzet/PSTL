#pragma once

#include <SDL2/SDL_image.h> 
#include <SDL2/SDL.h>


unsigned char *image_data;

void fastlay(SDL_Window *window, SDL_Renderer *renderer, SDL_Surface* screenshot);
unsigned char *setimage(void);
