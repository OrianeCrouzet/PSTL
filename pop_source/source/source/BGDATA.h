#pragma once
#define loose 11
#define numblox  2
#define panelwof 12
#define STA 2  // Opacité normale
#define ORA 1  // Opacité spécifique à dodrawc
#define DPRESSPLATE 5 //;down
#define PRESSPLATE 6 //;up
#define Ffalling 10
#define space 0
#define upressplate 15
#define floor 1
#define dpressplate 5 //down
#define gate 4
#define spikeExt 5 

#define spikes 2
#define posts 3
#define numpans 3
#define numbpans 
#define flask 10
#define pillartop 9
#define sword 22
#define archtop1 26
#define torch 19
#define archtop2 27
#define slicer 18


#define panelc0  0x9F
#define gatecmask 0x0D
#define panelb0 0x9E
#define gatebotSTA 0x43
#define gateB1 0x37
#define gatebotORA 0x44
#define looseb 0x1B
#define stairs 0x6B
#define doormask 0x6D
#define door 0x6C
#define toprepair 0x6E
#define slicerRet 6 //must match MOVEDATA
#define panelwif  7            //w floor
#define archpanel 0xA1
#define specialflask  0x95 
#define swordgleam0 0x99
#define swordgleam1 0xB3


/*Données blueprint*/
extern unsigned char **BlueType;
extern unsigned char **BlueSpec;
extern unsigned char *Table;

extern const unsigned char loosed[] ;

extern const unsigned char pieced[];

extern unsigned char blockd[2];
extern unsigned char blockc[2];
extern unsigned char piecec[] ;

extern unsigned char panelc[] ;

extern unsigned char maskb[];

extern unsigned char gate8c[] ;

extern unsigned char spaceb[] ;
extern unsigned char spaceby[] ;

extern unsigned char floorb[] ;
extern unsigned char floorby[];

extern unsigned char blockb[];
extern int pieceby[] ;
extern unsigned char pieceb[];


extern unsigned char bstripe[] ;

extern unsigned char panelb[] ;

extern unsigned char gate8b[] ;
extern unsigned char spikeb[] ;



extern unsigned char looseby[];

extern unsigned char pieceay[];
extern unsigned char loosea[];
extern unsigned char piecea[];

extern unsigned char maska[16] ;

extern unsigned char fronti[] ;
extern int fronty[] ;
extern int frontx[];
extern unsigned char blockfr[] ;
extern unsigned char slicerseq[] ;
extern unsigned char slicerfrnt[] ;

extern unsigned char spikea[] ;

extern unsigned char  slicerbot[] ;

extern unsigned char slicerbot2[] ;

extern unsigned char slicertop[] ;

extern unsigned char slicergap[] ;

