
//#include "Global.h"
#include <stdio.h>
#include "EQ.h"
#include "FrameAdV.h"



void DoSure(){//numero du screen qu'on souhaite dessiner, on le met à 1
    printf("je suis dans DOSURE\n");
 //SCRNUM = VisScrn; 


 zerolsts();

 sure();

 zeropeels();
 zerored();

 drawall();


}



int main(){
 
    DoSure();

    for(int i=1; i<=50;i++){

        printf("bgIMG %d %d\n ", i,bgIMG[i] );
        printf("bgX %d %d\n ", i,bgX[i] );
        printf("bgY %d %d\n ", i,bgY[i] );
        printf("OPACITYY %d %d\n ", i,bgOP[i] );

     

        // printf("fgIMG %d %d\n ", i,fgIMG[i] );
        // printf("fgX %d %d\n ", i,fgX[i] );
        // printf("fgY %d %d\n ", i,fgY[i] );



    }

    return 1;

}


//gcc topctrl.c FrameAdV.c Grafix.c GameBG.c hires.c BGDATA.c EQ.c GameEQ.c HRtables.c Tables.c  -o s  -lSDL2 -lSDL2_image