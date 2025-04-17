//#include "Global.h"
#include "GameBG.h"
#include "EQ.h"
#include "BGDATA.h"
#include "MOVEDATA.h"
#include "Grafix.h"



void setupflame(int spreced){
     if(spreced >=torchLast+1) return;

     IMAGE=torchflame[spreced];

     XCO++;

     YCO=YCO-43;

     OPACITY= STA;

     //mettre bgtab1 dans TAble
     setbgimg_bis("IMG.BGTAB1.DUN");

}

/******************************************
*  Set up to draw bubbling flask
*
* In/out: same as SETUPFLAME
*******************************************/

void setupflask(int st){

     OFFSET=boffset;

     if((st&0xE0)==EmptyPot){
          IMAGE=bubble[0];
          XCO++;
          XCO++;

          YCO=YCO-14;
          OPACITY=STA;

          setbgimg_bis("IMG.BGTAB2.DUN");

         return;
     }
     else{

          if((st&0xE0)==BoostPot){
          //special flask (taller)
               YCO=YCO-4;
              
           }else if((st&0xE0)>BoostPot){
               OFFSET++;
               YCO=YCO-4; 
           }

           if((st&0x1F)<bubbLast+1){
              IMAGE= bubble[st&0x1F];

           }
           else{

               IMAGE= bubble[0];
           }

           XCO++;
           XCO++;
           YCO=YCO-14;
           OPACITY=STA;

           setbgimg_bis("IMG.BGTAB2.DUN");
           return;
}
}