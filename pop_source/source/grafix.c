//
// Created by OrianeCrouzet on 08/03/2025.
//

#include "../utils/global.h"
#include "grafix.h"
#include "fRDr.h"

#define COPY_PROTECT 1

// *********************** Fonctions à implémenter dans d'autres fichiers ***********************
void gtone();

// *********************** Fonctions de dessins ***********************
void GR() {
    gtone(); // temp!
}

/*-------------------------------
*
*  Z E R O P E E L
*
*  Zero peel list & buffer for whichever page we're on
*
*  (Point PEELBUF to beginning of appropriate peel buffer
*  & set #-of-images byte to zero)
*
*-------------------------------*/
void ZEROPEEL() {
    if (PAGE == 0) {
        peelX[0] = 0;
        PEELBUF = peelbuf1;
    } else {
        peelX[MAX_PEEL] = 0;
        PEELBUF = peelbuf2;
    }
}

/*-------------------------------
*
*  S N G   P E E L
*
*  Draw peel list (in reverse order) using "peel" (fastlay)
*
*-------------------------------*/
void SNGPEEL() {
    uint8_t index = (PAGE == 0) ? 0 : MAX_PEEL;

    uint8_t count = peelX[index];
    if (count == 0) {
        return; // Rien à afficher
    }

    while (count > 0) {
        IMAGE = (peelIMGH[index] << 8) | peelIMGL[index];
        XCO = peelX[index];
        YCO = peelY[index];
        OPACITY = STA;

        peel();

        count--;
    }
}

/*-------------------------------
*
*  D O G E N
*
*  Do general stuff like clear screen
*
*-------------------------------*/
void DOGEN() {
    if (genCLS != 0) {
        CLS();  // Appelle la fonction d'effacement de l'écran
    }

    // "Purple copy-protection"
    if (BGset1 == 1) {
        dummy[BGset1 - 1] = 0;
    }
}

/*-------------------------------
*
*  D R A W W I P E
*
*  Draw wipe list (using "fastblack")
*
*-------------------------------*/
void DRAWWIPE() {
    if (wipeX[0] == 0) return;

    for (uint8_t i = 1; i <= wipeX[0]; i++) {
        height = wipeH[i];
        width = wipeW[i];

        XCO = wipeX[i];
        YCO = wipeY[i];

        OPACITY = wipeCOL[i];

        fastblack();
    }
}

/*-------------------------------
*
*  S E T   B  G   I M A G E
*
*  In: IMAGE = coded image #
*  Out: BANK, TABLE, IMAGE set for hires call
*
*  Protect A,X
*
*-------------------------------*/
void setBgImg(uint16_t imageCode) {
    IMAGE = imageCode & 0x7F;  // On garde IMAGE comme identifiant d'image

    if (imageCode & 0x80) {
        BANK = 3;
        IMAGE_TEXTURE = bgTable2[IMAGE];  // Charge l’image depuis la banque 2
    } else {
        BANK = 2;
        IMAGE_TEXTURE = bgTable1[IMAGE];  // Charge l’image depuis la banque 1
    }
}


/*-------------------------------
*
*  D R A W B A C K
*
*  Draw b.g. list (using fastlay)
*
*-------------------------------*/
void DRAWBACK(SDL_Renderer *renderer) {
    // Vérifier si la liste d'images de fond est vide
    if (bgX[0] == 0) return;

    // Itération à partir de l'index 1
    for (uint8_t i = 1; i <= bgX[0]; i++) {
        // Récupérer l'image
        IMAGE = bgIMG[i];

        // Extraire TABLE, BANK, IMAGE
        setBgImg(IMAGE);

        // Position et opacité
        XCO = bgX[i];
        YCO = bgY[i];
        OPACITY = bgOP[i];

        // Appliquer l'image
        fastlay(renderer);
    }
}

void DRAWMID();

/*-------------------------------
*
*  D R A W F O R E
*
*  Draw foreground list (using fastmask/fastlay)
*
*-------------------------------*/
void DRAWFORE();


void DRAWMSG();

/*-------------------------------
*
*  D R A W A L L
*
*  Draw everything in image lists
*
*  This is the only routine that calls HIRES routines.
*
*-------------------------------*/
void DRAWALL(SDL_Renderer *renderer) {
    // DOGEN();  // ;Do general stuff like cls

    // if (blackflag) {  // (temporaire ?)
    //     ZEROPEEL(); // ;Zero just-used peel list
    // } else {
    //     SNGPEEL();  // ;"Peel off" characters (using the peel list we set up 2 frames ago)
    //     ZEROPEEL(); // ;Zero just-used peel list
    // }

    //DRAWWIPE();  // ;Draw wipes
    DRAWBACK(renderer);  // ;Draw background plane images
    //DRAWMID();   // ;Draw middle plane images (& save underlayers to now-clear peel list)
    //DRAWFORE();  // ;Draw foreground plane images

    //DRAWMSG();   // ;Draw messages
}

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

// VBL (Vertical Blank Interrupt)
void VBLANK();
void VBLI();
