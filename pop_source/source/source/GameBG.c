#include "Global.h"

unsigned char torchflame[] = {
    0x52, 0x53, 0x54, 0x55, 0x56, 0x61, 0x62, 0x63, 0x64, 0x52, 0x54, 0x56
};

int ptorchflame[] = {
    1, 2, 3, 4, 5, 6, 7, 8, 9, 3, 5, 7, 1, 4, 9, 2, 8, 6
};

void setupflame(int spreced){
     if(spreced >=torchLast+1) return;

     IMAGE=torchflame[spreced];

     XCO++;

     YCO=YCO-43;

     OPACITY= STA;

     //mettre bgtab1 dans TAble
     setbgimg_bis("IMG.BGTAB1.DUN");

}