//
// Created by OrianeCrouzet on 27/02/2025.
//

#include "types.h"
#include "bgdata.h"
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#ifndef VARS_H
#define VARS_H

// Variables
extern uint8_t block_index;       // Index pour les boucles
extern uint8_t rowno;       // Numéro de ligne
extern uint8_t colno;       // Numéro de colonne
extern uint8_t yindex;      // Index Y
extern uint8_t objid;       // ID de l'objet
extern uint8_t state;       // État de l'objet
extern uint8_t Ay;          // Coordonnée Y pour la section A
extern uint8_t Dy;          // Coordonnée Y pour la section D
extern uint8_t gateposn;    // Position de la porte
extern uint8_t gatebot;     // Position du bas de la porte
extern uint8_t xsave;       // Sauvegarde de la coordonnée X
extern uint8_t blockxco;    // Coordonnée X du bloc
extern uint8_t switches;    // États des interrupteurs
extern uint8_t obj1;        // Objet 1
extern uint8_t obj2;        // Objet 2
extern uint8_t blockthr;    // Seuil du bloc
extern uint8_t level;        // Niveau actuel
extern uint8_t genCLS; // Effacer l'écran
extern uint8_t SCRNUM; // Numéro de l'écran actuel
extern uint8_t PRECED; // Bloc précédent
extern uint8_t spreced; // État du bloc précédent
extern uint8_t scrnBelow; // Écran en dessous
extern uint8_t scrnBelowL; // Écran en dessous (partie gauche)
extern uint8_t scrnAbove; // Écran au-dessus
extern uint8_t scrnLeft; // Écran à gauche
extern uint8_t redkidmeter; // Indicateur de redraw pour le compteur de force du joueur
extern uint8_t redoppmeter; // Indicateur de redraw pour le compteur de force de l'opposant
extern uint8_t inbuilder; // Indicateur de mode éditeur
extern uint8_t objX;  // Nombre d'objets actifs
extern uint8_t XCO, YCO, OFFSET, IMAGE, TABLE;
extern uint8_t FCharX, FCharY, FCharFace;
extern uint8_t FCharCU, FCharCD, FCharCL, FCharCR;
extern uint8_t IMAGE;   // Image affichée
extern uint8_t OPACITY;  // Gestion de l'opacité du sprite
extern uint8_t numblox;      // Nombre max de blocs
extern uint8_t scrnRight;
extern uint8_t KidBlockX, KidBlockY, KidScrn;
extern uint8_t numpans;
extern uint8_t BGset1;
extern uint8_t height, width;
extern uint8_t looseb;
extern uint8_t doortop, KidStartScrn;
extern uint8_t FCharImage;
extern uint8_t y;  // Variable globale pour l’index `y`

// Tableaux
extern uint8_t BlockBot[SCREEN_HEIGHT]; // Exemple de coordonnées Y
extern uint8_t Mult10[SCREEN_HEIGHT]; // Index des blocs
extern uint8_t PREV[SCREEN_HEIGHT]; // Blocs précédents
extern uint8_t sprev[SCREEN_HEIGHT]; // États des blocs précédents
extern uint8_t objINDX[256]; // Index des objets
extern uint8_t BlueType[256], BlueSpec[256];
extern uint8_t LINKMAP[256];
extern uint8_t objY[256];  // Coordonnée Y de chaque objet
extern uint8_t objTYP[256];  // Type d'objet
extern uint8_t whitebuf[256];  // Buffer d’effacement
extern uint8_t sortX[MAX_OBJECTS];  // Liste triée des objets
extern uint8_t PREV[3];          // Objets des 3 blocs les plus à droite de l'écran gauche
extern uint8_t sprev[3];         // États des objets précédents
extern GameObject objTable[MAX_OBJECTS];
extern GameObject objList[MAX_OBJECTS];  // Liste des objets du niveau
extern uint8_t BELOW[10];    // Objets sous la ligne actuelle
extern uint8_t SBELOW[10];   // États des objets sous la ligne

#endif //VARS_H
