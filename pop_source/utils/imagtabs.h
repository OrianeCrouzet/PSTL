//
// Created by OrianeCrouzet on 08/03/2025.
//

#include <stdint.h>

#ifndef IMAGTABS_H
#define IMAGTABS_H

static const uint8_t CH_TAB_BANK[] = {2, 2, 2, 3, 2, 3, 3};

static const uint8_t* CH_TAB_LIST[] = {
    (uint8_t*) 0xchtable1, (uint8_t*) 0xchtable2,
    (uint8_t*) 0xchtable3, (uint8_t*) 0xchtable4,
    (uint8_t*) 0xchtable5, (uint8_t*) 0xchtable6,
    (uint8_t*) 0xchtable7
};

extern uint8_t dummy[];

#endif //IMAGTABS_H
