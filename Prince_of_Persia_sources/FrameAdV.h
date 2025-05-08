#pragma once
#include <stdbool.h>

/****************************************
 *         Declarations
 ****************************************/

 extern int Dy;
 extern int Ay;
 extern int yindex;
 extern int blockxco;
 extern int objid;
 extern int state;

 extern bool  carry;
 extern int pile;
 extern int gateposn;
 extern int blockthr;
 extern int gatebot;
 extern int KidStartScrn;
 extern int xsave;
 extern int BASE[192][280];





 
 void maddfore();
 void drawslicerf();
 void drawfrnt();
 void drawma();
 void drawsworda();
 int getpiecea(int objid);
 void addamask();
 void adda();
 void adda1(int arch, int x);
 void drawa();
 void drawexitb();
 void drawtorchb();
 void drawlooseb();
 void drawspikeb();
 void restorebot(int colno);
 void setupdgb();
 void drawgateb(int colno);
 void drawmb(int colno);
 void drawb();
 void drawgatec(int colno);
 void drawmc(int colno);
 void domaskb();
 void dodrawc(int colno);
 void checkc();
 void drawc(int colno);
 void getbelow(int rowno);
 void getprev();
 int Gonull();
 int getobjid(int yindex);
 int getobjid1(int yindex);
 int getobjbldr();
 void sure();
 int getloosey(int st);
 void  zerolsts();
 void  zeropeels();
 void  zerored();
 void drawall();
 void DoSure();