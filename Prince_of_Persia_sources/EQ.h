#pragma once 




/*variable de image list*/
#define maxback 200
#define maxfore 100 //x4
#define maxwipe 20 //x5
#define maxpeel 46 //x4
#define maxmid 46 //x11
#define maxobj 20 //x12
#define maxmsg 32 //x5
#define maxpeel 46
#define gmaxval 47*4
#define gminval 0
#define my_mask 4
#define maxfore 100


extern int BANK;
extern int  genCLS; 
extern int XCO;
extern int YCO;
extern int SCRNUM;
extern int OPACITY; //0-5
extern int IMAGE;
extern int OFFSET;
extern int peelX[maxpeel * 2];

extern int bgX[maxback];
extern int bgY[maxback]; 
extern int bgIMG[maxback];
extern int bgOP[maxback]; 

extern int fgX[maxfore];
extern int fgY[maxfore];
extern int fgOP[maxfore];
extern int fgIMG[maxfore];

extern int midX[maxfore];
extern int midTYP[maxfore];
extern int midOFF[maxfore];
extern int midY[maxfore];
extern int midIMG[maxfore];
extern int midOP[maxfore];
extern int midCU[maxfore];
extern int midCL[maxfore];
extern int midCR[maxfore];
extern int midCD[maxfore];

extern unsigned char idmask;
extern int inbuilder;
extern int peelX[maxpeel*2];
extern int  fredbuf[30];
extern int floorbuf[30];
extern int  loorbuf[30];
extern int  halfbuf[30];  
extern int  wipebuf[30];
extern int  movebuf[30];
extern int objbuf[30];
extern int topbuf[30];
extern int PREV[3];
extern int sprev[3];
extern int PRECED;
extern int spreced;
extern int BELOW[16];
extern int SBELOW[16];
extern unsigned char *LINKMAP;
extern int level;
extern int and ;
extern int dummy[];



extern int initsettings[];



extern const int ScrnLeft ;
extern const int ScrnTop;
extern const int ScrnBot ;
extern const int BlockHeight ;

extern const int Blox1;
extern const int Blox2 ;
extern const int Blox3 ;
extern const int Blox4 ;


extern const int BlockBot[];