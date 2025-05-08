#pragma once
#define EmptyPot    0x00
#define RefreshPot  0x20
#define BoostPot    0x40
#define MystPot     0x60
#define boffset 2


extern unsigned char torchflame[];
extern int ptorchflame[];
extern unsigned char bubble[] ;

void setupflame(int sp);

void setupflask(int st);
