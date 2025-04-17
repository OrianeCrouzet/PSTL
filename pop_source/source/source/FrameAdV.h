#pragma once
#include <stdbool.h>

/****************************************
 *         Declarations
 ****************************************/

 int Dy;
 int Ay;
 int yindex;
 int blockxco;
 int objid;
 int state;

 bool  carry= false;
 int pile;
 int gateposn;
 int blockthr;
 int gatebot;
 int KidStartScrn=2;
 int xsave;




 
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