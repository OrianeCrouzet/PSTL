//
// Created by OrianeCrouzet on 27/02/2025.
//

#include <stdint.h>
#ifndef BGDATA_H
#define BGDATA_H

/*-------------------------------
* Indexed by PIECE ID#:
*/

#define SPACE 0
#define FLOOR 1
#define SPIKES 2
#define POSTS 3
#define GATE 4
#define DPRESSPLATE 5 //;down
#define PRESSPLATE 6 //;up
#define PANELWIF 7 //;w/floor
#define PILLARBOTTOM 8
#define PILLARTOP 9
#define FLASK 10
#define LOOSE 11
#define PANELWOF 12 //;w/o floor
#define MIRROR 13
#define RUBBLE 14
#define UPRESSPLATE 15
#define EXIT 16
#define EXIT2 17
#define SLICER 18
#define TORCH 19
#define BLOCK 20
#define BONES 21
#define SWORD 22
#define WINDOW 23
#define WINDOW2 24
#define ARCHBOT 25
#define ARCHTOP1 26
#define ARCHTOP2 27
#define ARCHTOP3 28
#define ARCHTOP4 29

/*-------------------------------
* A & B sections have l.l. of (X = BlockLeft, Y = BlockBot-3)
* C & D sections have l.l. of (X = BlockLeft, Y = BlockBot)
* All x & y offsets are relative to these values
* (Front pieces are relative to A)

*-------------------------------
*               0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15
*              16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31
*/

const uint8_t maska[30] = {
    0x00, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x00,
    0x03, 0x03, 0x00, 0x03, 0x03, 0x03, 0x03, 0x00, 0x00, 0x03,
    0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00
};

const uint8_t piecea[30] = {
    0x00, 0x01, 0x05, 0x07, 0x0A, 0x01, 0x01, 0x0A, 0x10, 0x00,
    0x01, 0x00, 0x00, 0x14, 0x20, 0x4B, 0x01, 0x00, 0x00, 0x01,
    0x00, 0x97, 0x00, 0x01, 0x00, 0xA7, 0xA9, 0xAA, 0xAC, 0xAD
};

// `dfb` = valeurs signées, donc `int8_t`
const int8_t pieceay[30] = {
    0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -4, -4, -4, 0
};

const uint8_t maskb[30] = {
    0x00, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x00, 0x04, 0x00,
    0x04, 0x00, 0x00, 0x04, 0x04, 0x04, 0x00, 0x04, 0x04, 0x04,
    0x04, 0x04, 0x04, 0x00, 0x04, 0x04, 0x00, 0x00, 0x00, 0x00
};

const uint8_t pieceb[30] = {
    0x00, 0x02, 0x06, 0x08, 0x0B, 0x1B, 0x02, 0x9E, 0x1A, 0x1C,
    0x02, 0x00, 0x9E, 0x4A, 0x21, 0x1B, 0x4D, 0x4E, 0x02, 0x51,
    0x84, 0x98, 0x02, 0x91, 0x92, 0x02, 0x00, 0x00, 0x00, 0x00
};

const int8_t pieceby[30] = {
    0, 0, 0, 0, 0, 1, 0, 3, 0, 3,
    0, 0, 3, 0, 0, -1, 0, 0, 0, -1,
    2, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

const uint8_t bstripe[30] = {
    0x00, 0x47, 0x47, 0x00, 0x00, 0x47, 0x47, 0x00, 0x00, 0x00,
    0x47, 0x47, 0x00, 0x00, 0x47, 0x47, 0x00, 0x00, 0x47, 0x00,
    0x00, 0x00, 0x47, 0x00, 0x00, 0x47, 0x00, 0x00, 0x00, 0x00
};

const uint8_t piecec[30] = {
    0x00, 0x00, 0x00, 0x09, 0x0C, 0x00, 0x00, 0x9F, 0x00, 0x1D,
    0x00, 0x00, 0x9F, 0x00, 0x00, 0x00, 0x4F, 0x50, 0x00, 0x00,
    0x85, 0x00, 0x00, 0x93, 0x94, 0x00, 0x00, 0x00, 0x00, 0x00
};

const uint8_t pieced[30] = {
    0x00, 0x15, 0x15, 0x15, 0x15, 0x18, 0x19, 0x16, 0x15, 0x00,
    0x15, 0x00, 0x17, 0x15, 0x2E, 0x4C, 0x15, 0x15, 0x15, 0x15,
    0x86, 0x15, 0x15, 0x15, 0x15, 0x15, 0xAB, 0x00, 0x00, 0x00
};

const uint8_t fronti[30] = {
    0x00, 0x00, 0x00, 0x45, 0x46, 0x00, 0x00, 0x46, 0x48, 0x49,
    0x87, 0x00, 0x46, 0x0F, 0x13, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x83, 0x00, 0x00, 0x00, 0x00, 0xA8, 0x00, 0xAE, 0xAE, 0xAE
};

const int8_t fronty[30] = {
    0, 0, 0, -1, 0, 0, 0, 0, -1, 3,
    -3, 0, 0, -1, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -1, 0, -36, -36, -36
};

const uint8_t frontx[30] = {
    0x00, 0x00, 0x00, 0x01, 0x03, 0x00, 0x00, 0x03, 0x01, 0x01,
    0x02, 0x00, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00
};

/**-------------------------------
* special pieces
*/
#define GATEBOT_STA  0x43
#define GATEBOT_ORA  0x44
#define GATEB1       0x37
#define GATEC_MASK   0x0D

// **Gate 8-segment pieces**
const uint8_t gate8c[8] = { 0x2F, 0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36 };
const uint8_t gate8b[8] = { 0x3E, 0x3D, 0x3C, 0x3B, 0x3A, 0x39, 0x38, 0x37 };

/*-------------------------------
* Climbup masking
*/
#define CUMASK   0x11
#define CUPIECE  0x12
#define CUPOST   0x0E

/*-------------------------------
* Exit
*/
#define STAIRS      0x6B
#define DOOR        0x6C
#define DOORMASK    0x6D
#define TOPREPAIR   0x6E
#define ARCHTOP3SP  0xA1

/*-------------------------------
* Spike animation frames
*               0  1  2  3  4  5  6  7  8  9 10 11
*/
#define SPIKE_EXT  5
#define SPIKE_RET  9  // must match MOVEDATA

const uint8_t spikea[10] = {
    0x00, 0x22, 0x24, 0x26, 0x28, 0x2A, 0x28, 0x24, 0x22, 0x00
};

const uint8_t spikeb[10] = {
    0x00, 0x23, 0x25, 0x27, 0x29, 0x2B, 0x29, 0x25, 0x23, 0x00
};

/*-------------------------------
* Slicer animation frames
*               0  1  2  3  4  5  6  7  8  9 10 11
*/
#define SLICER_EXT  2
#define SLICER_RET  6  // must match MOVEDATA

const uint8_t slicerseq[7] = { 4, 3, 1, 2, 5, 4, 4 };
const uint8_t slicertop[5] = { 0x00, 0x58, 0x5A, 0x5C, 0x5E };
const uint8_t slicerbot[5] = { 0x57, 0x59, 0x5B, 0x5D, 0x5F };
const uint8_t slicerbot2[5] = { 0x8E, 0x8F, 0x90, 0x5D, 0x5F };
const int8_t slicergap[5] = { 0, 56, 70, 83, 85 };
const uint8_t slicerfrnt[5] = { 0x65, 0x66, 0x67, 0x68, 0x69 };

/*-------------------------------
* Loose floor
*               0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15
*/
#define LOOSEB  0x1B  // Identifiant de la section B du sol fragile
#define FFALLING 10   // Première frame de chute (doit correspondre à MOVEDATA)

const uint8_t loosea[11] = {
    0x01, 0x1E, 0x01, 0x1F, 0x1F, 0x01, 0x01, 0x01, 0x1F, 0x1F, 0x1F
};

const int8_t looseby[11] = {
    0, 1, 0, -1, -1, 0, 0, 0, -1, -1, -1
};

const uint8_t loosed[11] = {
    0x15, 0x2C, 0x15, 0x2D, 0x2D, 0x15, 0x15, 0x15, 0x2D, 0x2D, 0x2D
};

/*-------------------------------*/
#define SPECIALFLASK  0x95  // Potion spéciale
#define SWORDGLEAM1   0xB3  // Épée brillante (animation)
#define SWORDGLEAM0   0x99  // Épée normale

/*-------------------------------
* panels
*/
#define PANELB0  0x9E
#define PANELC0  0x9F
#define NUMPANS  3  // Nombre total de panneaux

const uint8_t panelb[3] = { 0x9E, 0x9A, 0x81 };
const uint8_t panelc[3] = { 0x9F, 0x9B, 0x82 };

#define ARCHPANEL  0xA1  // Arche spéciale

/*-------------------------------
* back wall panels for space & floor
*/
#define NUMBPANS  3  // Nombre de panneaux muraux

const uint8_t spaceb[4] = { 0x00, 0xA3, 0xA5, 0xA6 };
const int8_t spaceby[4] = { 0, -20, -20, 0 };

const uint8_t floorb[4] = { 0x02, 0xA2, 0xA4, 0xA4 };
const int8_t floorby[4] = { 0, 0, 0, 0 };

/*-------------------------------
* solid blocks
*/
#define NUMBLOX  2  // Nombre de blocs solides

const uint8_t blockb[2] = { 0x84, 0x6F };
const uint8_t blockc[2] = { 0x85, 0x85 };
const uint8_t blockd[2] = { 0x86, 0x86 };
const uint8_t blockfr[2] = { 0x83, 0x83 };

/*-------------------------------
* moveparams
*/
#define GMAXVAL  (47 * 4)  // Valeur max de mouvement de la grille
#define GMINVAL  0         // Valeur min de mouvement de la grille


//-------------------------------------------------------------------------------
/* Les valeurs des constantes seront à vérifier dans les autres fichiers du jeu */
#define EditorDisk 0 // 1 = dunj, 2 = palace
#define org 0x1290   // Adresse d'origine en assembleur
#define SCREEN_WIDTH 10
#define SCREEN_HEIGHT 3
#define BLOCK_SIZE 4 // Taille d'un bloc en pixels (exemple)
#define MAX_OBJECTS 50  // Nombre maximum d'objets affichables
#define BLOCK_ID 1  // ID utilisé pour un bloc standard
#define LEVEL_MAX 12
#define SPECIAL_FLASK 99
#define ORA 1  // Opacité spécifique à dodrawc
#define AND 2  // Opacité spécifique pour `domaskb`
#define STA 2  // Opacité normale
#define SPIKEEXT 7  // Piques étendues
#define SLICERRET 5
#define STA_OPACITY 3
#define AND_OPACITY 2
#define ORA_OPACITY 1
#define GATEMASK 20
#define MAX_HEIGHT 192
#define TYPE_KID 1
#define TYPE_REFLECT 2
#define TYPE_SHAD 3
#define TYPE_FF 4
#define TYPE_SWORD 5
#define TYPE_COMIX 6
#define TYPE_GD 7
#define USELAYRSAVE 4
#define USELAY 5
#define IDMASK 0x1F

#endif //BGDATA_H
