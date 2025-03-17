//
// Created by OrianeCrouzet on 08/03/2025.
//

#include "global.h"

#ifndef GRAFIX_H
#define GRAFIX_H

void gtone();

void GR();

void ZEROPEEL();
void SNGPEEL();
void CLS();

void DOGEN();
void setBgImg(uint16_t imageCode);
void DRAWBACK(SDL_Renderer *renderer);
void DRAWMID();
void DRAWFORE();
void DRAWMSG();

void DRAWALL();

void CONTROLLER();
void dispversion();
void SAVEBLUE();
void RELOADBLUE();
void MOVEMEM();
void BUTTONS();
void GTONE();
void SETCENTER();

void DIMCHAR();
void CVTX();
void ZEROPEELS();
void PREAD();

void ADDPEEL();
void COPYSCRN();
void RND();

void LAY();
void FASTLAY();
void LAYRSAVE();
void LRCLS();
void FASTMASK();

void FASTBLACK();
void PEEL();
void GETWIDTH();
void COPY2000();
void COPY2000MA();

void SETFASTAUX();
void SETFASTMAIN();
void LOADLEVEL();
void ATTRACTMODE();
void XMINIT();

void XMPLAY();
void CUTPRINCESS();
void XTITLE();
void COPY2000AM();
void RELOAD();

void LOADSTAGE2();
void GETSELECT();
void GETDESEL();
void EDREBOOT();

void GOBUILD();
void GOGAME();
void WRITEDIR();
void READDIR();
void SAVELEVEL();

void SAVELEVELG();
void ADDBACK();
void ADDFORE();
void ADDMID();
void ADDMIDEZ();

void ADDWIPE();
void ADDMSG();
void SAVEGAME();
void LOADGAME();
void ZEROLSTS();

void SCREENDUMP();
void MINIT();
void MPLAY();
void SAVEBINFO();
void RELOADBINFO();

void INVERTY();
void NORMSPEED();
void ADDMIDEZO();
void CALCBLUE();
void ZERORED();

void XPLAYCUT();
void CHECKIIGS();
void FASTSPEED();
void MUSICKEYS();
void DOSTARTGAME();

void EPILOG();
void LOADALTSET();
void XMOVEMUSIC();
void WHOOP();

void VBLANK();
void VBLI();

// Pointeur vers la fonction VBLANK (modifiée si nécessaire)
void (*VBLvect)() = VBLANK;

#endif //GRAFIX_H
