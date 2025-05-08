
#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h> 

void addfore(void);
void addback(void);
void drawall(void);
void DRAWBACK(SDL_Window *window, SDL_Renderer *renderer, SDL_Surface* screenshot);
void setbgimg(void);
void setbgimg_bis(char ImgTab[15]);
void zerored(void);
void zeropeels(void);
void DOGEN(void);
void zerolsts(void);
void calcblue(char ImgTab[7]);
void addmidezo();

