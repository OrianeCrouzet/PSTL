//
// Created by OrianeCrouzet on 27/02/2025.
//

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#ifndef TYPES_H
#define TYPES_H

// Structures
typedef struct {
    uint8_t x;      // Position X
    uint8_t y;      // Position Y
    uint8_t offset; // Décalage
    uint8_t img;    // Image de l'objet
    uint8_t face;   // Orientation (gauche/droite)
    uint8_t type;   // Type d'objet
    uint8_t cu, cd, cl, cr; // Déplacements possibles (Up, Down, Left, Right)
    uint8_t tab;    // Valeur spécifique à l'objet
    uint8_t index;  // Identifiant de l'objet
} GameObject;

#endif //TYPES_H
