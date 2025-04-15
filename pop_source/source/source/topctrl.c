
#include "Global.h"


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

    for(int i=1; i<=200;i++){

        printf("bgIMG %d %d\n ", i,bgIMG[i] );
        printf("bgX %d %d\n ", i,bgX[i] );
        printf("bgY %d %d\n ", i,bgY[i] );
        printf("HELLO");



    }

    return 1;

}
