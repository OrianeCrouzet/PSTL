#pragma once

#include <SDL2/SDL_image.h> 
#include <SDL2/SDL.h>


extern unsigned char *image_data;

extern void fastlay(SDL_Window *window, SDL_Renderer *renderer, SDL_Surface* screenshot);

unsigned char *setimage(void);
