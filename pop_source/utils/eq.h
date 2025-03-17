//
// Created by OrianeCrouzet on 08/03/2025.
//

#include "global.h"

#ifndef EQ_H
#define EQ_H

/*-------------------------------
*
*  Equates
*
*-------------------------------*/
// Main l.c.
#define RW18        0xD000
#define PEELBUF1    0xD000
#define PEELBUF2    0xD800
#define HRTABLES    0xE000
#define UNPACK      0xEA00 // ;game only
#define HIRES       0xEE00
#define MASTER      0xF880

// Auxmem
#define GRAFIX      0x0400
#define TABLES      0x0E00
#define FRAMEADV    0x1290
#define REDBUFS     0x5E00
#define MENUDATA    0x960F  // ;ed only
#define IMLISTS     0xAC00
#define ENDIMSPACE  0xB600
#define BLUEPRNT    0xB700

// Aux l.c.
#define BLUECOPY    0xD000  // ;bank 1

/*-------------------------------
*
*  Blueprint info
*
*-------------------------------*/
#define INFO_RESERVED_SIZE 64
extern uint8_t INFO_RESERVED[INFO_RESERVED_SIZE];

extern uint8_t KidStartScrn;   // Écran de départ du Kid
extern uint8_t KidStartBlock;  // Bloc de départ du Kid
extern uint8_t KidStartFace;   // Orientation de départ du Kid

extern uint8_t SwStartScrn;    // Écran de départ de l'épée
extern uint8_t SwStartBlock;   // Bloc de départ de l'épée

#define NUM_GUARDS 24
extern uint8_t GdStartBlock[NUM_GUARDS]; // Bloc de départ des gardiens
extern uint8_t GdStartFace[NUM_GUARDS];  // Orientation des gardiens
extern uint8_t GdStartX[NUM_GUARDS];     // Position X des gardiens
extern uint8_t GdStartSeqL[NUM_GUARDS];  // Séquence basse des animations des gardiens
extern uint8_t GdStartProg[NUM_GUARDS];  // Progression des gardiens dans leur comportement
extern uint8_t GdStartSeqH[NUM_GUARDS];  // Séquence haute des animations des gardiens

/*-------------------------------
*
*  Image lists
*
*-------------------------------*/
// Définition des tailles maximales des listes d'images
#define MAX_BACK  200  // Background images
#define MAX_FORE  100  // Foreground images
#define MAX_WIPE   20  // Wipe effects
#define MAX_PEEL   46  // Peel images
#define MAX_MID    46  // Mid-layer images
#define MAX_OBJ    20  // Objects
#define MAX_MSG    32  // Messages

// Génération du flag d'effacement d'écran
extern uint8_t genCLS;

// Background (plan arrière)
extern uint8_t bgX[MAX_BACK];
extern uint8_t bgY[MAX_BACK];
extern uint16_t bgIMG[MAX_BACK];
extern uint8_t bgOP[MAX_BACK];

// Foreground (premier plan)
extern uint8_t fgX[MAX_FORE];
extern uint8_t fgY[MAX_FORE];
extern uint16_t fgIMG[MAX_FORE];
extern uint8_t fgOP[MAX_FORE];

// Wipe effects
extern uint8_t wipeX[MAX_WIPE];
extern uint8_t wipeY[MAX_WIPE];
extern uint8_t wipeH[MAX_WIPE];
extern uint8_t wipeW[MAX_WIPE];
extern uint8_t wipeCOL[MAX_WIPE];

// Peel (images à détacher)
extern uint8_t peelX[MAX_PEEL * 2];
extern uint8_t peelY[MAX_PEEL * 2];
extern uint8_t peelIMGL[MAX_PEEL * 2];
extern uint8_t peelIMGH[MAX_PEEL * 2];

// Mid-layer (couche intermédiaire)
extern uint8_t midX[MAX_MID];
extern uint8_t midOFF[MAX_MID];
extern uint8_t midY[MAX_MID];
extern uint16_t midIMG[MAX_MID];
extern uint8_t midOP[MAX_MID];
extern uint8_t midTYP[MAX_MID];
extern uint8_t midCU[MAX_MID];
extern uint8_t midCD[MAX_MID];
extern uint8_t midCL[MAX_MID];
extern uint8_t midCR[MAX_MID];
extern uint8_t midTAB[MAX_MID];

// Objects
extern uint8_t objINDX[MAX_OBJ];
extern uint8_t objX[MAX_OBJ];
extern uint8_t objOFF[MAX_OBJ];
extern uint8_t objY[MAX_OBJ];
extern uint16_t objIMG[MAX_OBJ];
extern uint8_t objFACE[MAX_OBJ];
extern uint8_t objTYP[MAX_OBJ];
extern uint8_t objCU[MAX_OBJ];
extern uint8_t objCD[MAX_OBJ];
extern uint8_t objCL[MAX_OBJ];
extern uint8_t objCR[MAX_OBJ];
extern uint8_t objTAB[MAX_OBJ];

// Messages
extern uint8_t msgX[MAX_MSG];
extern uint8_t msgOFF[MAX_MSG];
extern uint8_t msgY[MAX_MSG];
extern uint16_t msgIMG[MAX_MSG];
extern uint8_t msgOP[MAX_MSG];

/*-------------------------------
*
*  Zero page
*
*-------------------------------
*  $00-17: Hires parameters
*-------------------------------*/
extern uint8_t PAGE;
extern uint8_t XCO;
extern uint8_t YCO;
extern uint8_t OFFSET;
extern uint16_t IMAGE; // 2 octets
extern uint8_t OPACITY;
extern uint16_t TABLE; // 2 octets
extern uint16_t *PEELBUF; // 2 octets
extern uint16_t PEELIMG; // 2 octets
extern uint8_t PEELXCO;
extern uint8_t PEELYCO;
extern uint8_t TOPCUT;
extern uint8_t LEFTCUT;
extern uint8_t RIGHTCUT;
extern uint8_t BANK;
extern uint8_t BOTCUT;

// Alias pour IMAGE
#define height ((uint8_t*)&IMAGE)[0]  // Premier octet de IMAGE
#define width ((uint8_t*)&IMAGE)[1]   // Deuxième octet de IMAGE

/*-------------------------------
*  $18-3f: Global vars
*-------------------------------*/
extern uint8_t JSTKX;        // Position X du joystick
extern uint8_t JSTKY;        // Position Y du joystick
extern uint8_t BTN0;         // Bouton 0
extern uint8_t BTN1;         // Bouton 1
extern uint8_t BUTT0;        // Autre bouton 0
extern uint8_t BUTT1;        // Autre bouton 1
extern uint8_t JSTKUP;       // Indique si le joystick est en haut
extern uint8_t b0down;       // Bouton 0 enfoncé
extern uint8_t b1down;       // Bouton 1 enfoncé
extern uint8_t SINGSTEP;     // Indique une seule étape (single step mode)
extern uint8_t blackflag;    // Flag pour une action (ex: écran noir)
extern uint8_t SCRNUM;       // Numéro de l'écran actuel
extern uint16_t BlueType;    // Type d'élément en cours (2 octets)
extern uint16_t BlueSpec;    // Spécifications de l'élément en cours (2 octets)
extern uint8_t CUTTIMER;     // Timer pour une coupure (cinématique ?)
extern uint8_t PRECED;       // Bloc précédent
extern uint8_t spreced;      // État précédent du bloc
extern uint8_t PREV[3];      // 3 derniers blocs de l’écran précédent
extern uint8_t sprev[3];     // État des 3 derniers blocs
extern uint8_t scrnLeft;     // Numéro de l'écran à gauche
extern uint8_t scrnRight;    // Numéro de l'écran à droite
extern uint8_t scrnAbove;    // Numéro de l'écran au-dessus
extern uint8_t scrnBelow;    // Numéro de l'écran en dessous
extern uint8_t scrnBelowL;   // Écran en bas à gauche
extern uint8_t scrnAboveL;   // Écran en haut à gauche
extern uint8_t scrnAboveR;   // Écran en haut à droite
extern uint8_t scrnBelowR;   // Écran en bas à droite
extern uint8_t kbdX;         // Position X du clavier
extern uint8_t kbdY;         // Position Y du clavier
extern uint8_t joyX;         // Position X du joystick
extern uint8_t joyY;         // Position Y du joystick
extern uint8_t btn;          // État du bouton (global)
extern uint8_t butt;         // État d’un autre bouton

/*-------------------------------
*
*  Pages 2-3
*
*-------------------------------*/
extern uint8_t inmenu;        // Indique si on est dans un menu
extern uint8_t inbuilder;     // Mode "builder"
extern uint8_t ineditor;      // Mode éditeur
extern uint8_t soundon;       // Son activé ou non

extern uint16_t jctr;
extern uint8_t jthres1x;      // Seuil joystick X (1)
extern uint8_t jthres1y;      // Seuil joystick Y (1)
extern uint8_t jthres2x;      // Seuil joystick X (2)
extern uint8_t jthres2y;      // Seuil joystick Y (2)
extern uint8_t jvert;         // Indicateur vertical du joystick
extern uint8_t jhoriz;        // Indicateur horizontal du joystick
extern uint8_t jbtns;         // Boutons du joystick
extern uint8_t joyon;         // Indique si le joystick est activé

extern uint8_t develment;
extern uint8_t keypress;      // Dernière touche pressée
extern uint8_t keydown;       // Indicateur d'une touche enfoncée
extern uint8_t IIGS;          // Indicateur Apple IIgs

extern uint8_t sortX[16];     // Liste de tri des objets
extern uint8_t BELOW[16];     // Éléments sous-jacents
extern uint8_t SBELOW[16];    // États des éléments sous-jacents

extern uint8_t bluepTRK;
extern uint8_t bluepREG;
extern uint8_t binfoTRK;
extern uint8_t binfoREG;
extern uint8_t level;         // Niveau actuel
extern uint8_t BBundID;       // Identifiant du bundle
extern uint8_t redherring2;
extern uint8_t pausetemp;     // Stocke l’état avant pause
extern uint8_t recheck0;

/*-------------------------------
*
*  Misc. constants
*
*-------------------------------*/
#define SCRN_WIDTH 140
#define SCRN_HEIGHT 192

// Délimitation de l'écran
#define SCRN_LEFT 58
#define SCRN_RIGHT (SCRN_LEFT + SCRN_WIDTH - 1)
#define SCRN_TOP 0
#define SCRN_BOTTOM (SCRN_TOP + SCRN_HEIGHT - 1)

// Masques binaires
#define SECMASK 0b11000000  // Masque de section
#define REQMASK 0b00100000  // Masque de requête
#define IDMASK  0b00011111  // Masque d'identifiant

// Modes d'opération
#define OP_AND 0  // Opération logique AND
#define OP_ORA 1  // Opération logique OR
#define OP_STA 2  // Opération STA (stockage)
#define OP_EOR 3  // Opération XOR
#define OP_MASK 4 // Masque générique


#endif //EQ_H
