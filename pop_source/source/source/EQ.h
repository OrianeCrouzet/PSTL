#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL2/SDL.h>
#include <stdbool.h>
#include <SDL2/SDL_image.h> 


/*variable de image list*/
#define maxback 200
#define maxfore 100 //x
#define maxwipe 20 //x5
#define maxpeel 46 //x4
#define maxmid 46 //x11
#define maxobj 20 //x12
#define maxmsg 32 //x5
#define maxpeel 46
#define gmaxval 47*4
#define gminval 0

int BANK;
int  genCLS; 
int XCO;
int YCO;
int SCRNUM= 1;
int OPACITY; //0-5
int IMAGE;
int peelX[maxpeel * 2];
int bgX[maxback];
int bgY[maxback]; 
int bgIMG[maxback];
int bgOP[maxback]; 
unsigned char idmask= 0x1F;
int inbuilder=0;
int peelX[maxpeel*2];
int  fredbuf[30];
int floorbuf[30];
int  loorbuf[30];
int  halfbuf[30];  
int  wipebuf[30];
int  movebuf[30];
int objbuf[30];
int topbuf[30];
int PREV[3];
int sprev[3];
int PRECED;
int spreced;
int BELOW[16];
int SBELOW[16];
unsigned char *LINKMAP;
int level=1;
int and = 0;



/*variables initialisé dans zerolsts()*/
int  wipeX;
int  midX;
int  objX;
int  fgX;
int  msgX;


const int ScrnLeft = 58;
const int ScrnTop = 0;
const int ScrnBot = 191;
const int BlockHeight = 63;

const int Blox1 = BlockHeight;
const int Blox2 = 2*BlockHeight;
const int Blox3 = 3*BlockHeight;
const int Blox4 = 4*BlockHeight;


const int BlockBot[]= {ScrnBot+1-Blox4,
    ScrnBot+1-Blox3,
    ScrnBot+1-Blox2,
    ScrnBot+1-Blox1,
    ScrnBot+1};