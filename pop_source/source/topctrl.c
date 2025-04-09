#include "global.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL2/SDL.h>


#define maxpeel 46
#define Ffalling 10
#define numblox = 2
#define gmaxval 47*4
#define gminval 0
#define initsettings[]= {gmaxval,gminval}
#define dummy[]={maxpeel,maxpeel}
#define block 20
#define panelwof 12

unsigned char idmask= 0x1F;

#define space 0
#define upressplate 15
#define floor 1
#define dpressplate 5 //down
#define gate 4
#define loose 11
#define flask 10
int inbuilder=0;

/*Données blueprint*/
unsigned char **blueType;
unsigned char **blueSpec;
/*variable de image list*/
#define maxback 200
#define maxfore 100 //x
#define maxwipe 20 //x5
#define maxpeel 46 //x4
#define maxmid 46 //x11
#define maxobj 20 //x12
#define maxmsg 32 //x5
   
 int bgX[maxback];
 int bgY[maxback]; 
 int bgIMG[maxback];
 int bgOP[maxback]; 


/*variables initialisé dans zerolsts()*/
int  genCLS; 
int  wipeX;
int *bgX= (int *)malloc(maxback*sizeof(int));
int *bgY= (int *)malloc(maxback*sizeof(int));
int  midX;
int  objX;
int  fgX;
int  msgX;

void drawbg(){

    int cutplan= 0;
    int cuttimer= 0;

    DoSure(1);

    mermeters();//pas important
}

void zerolsts(){//remet plusieurs variables à 0
genCLS=0;
wipeX=0;


for(int i=0; i< maxback;i++){
    bgX[i]= 999;
}
midX=0;
objX=0;
fgX=0;
msgX=0;

}


void addback(){
    int x=0;
   if(bgX[maxback-1!=999]) return ;

   for(int i=0; i< maxback;i++){
    if (bgX[i]==999){
        x=i;
        break;
    }
   }

   bgX[x]= XCO;
   if(YCO==192) return;
   bgY[x]= YCO;
   bgIMG[x]= IMAGE;

   bgOP[x]= OPACITY;

}
void getloosey(){
    if (inbuilder==0){
        if(state>=0) return;

        if(state&0x7F<Ffalling+1) {}
        else{ lda 1}
       
    }
    ldy 1 
    return;

}
void drawloosed(){
    state
    getloosey();
    if(loosed[y]==0) return;
    IMAGE= loosed[y];

    XCO=blockxco;
    YCO=Dy;
    OPACITY=STA;

    addback();


}
void setback(){
    addback();// pas vraiment, ptr de fonction vers add back pour la prochaine fois qu'on appelle add
}

/*retourne le debut du blutype et du bluespec*/
void *calcblue(char ImgTab[7]){
    //if(SCRNUM==0) calcmenue() on s'en occupe pas maintenant
    FILE *file;


    
    file = fopen(ImgTab, "rb");

    if (file == NULL) {
        perror("Erreur d'ouverture du fichier");
        exit(1);
    }

    // Déplace l'offset à la fin du fichier
    fseek(file, 0, SEEK_END);

    // Renvoie la position de l'offset et donc la taille du fichier
    size_t file_size = ftell(file);

    if (file_size == -1) {
        perror("Erreur lors de la lecture de la taille du fichier");
        fclose(file);
        exit(1);
    }

    // Tableau qui va contenir le fichier
    unsigned char *fichier = (unsigned char *)malloc(file_size * sizeof(unsigned char));

    if (fichier == NULL) {
        perror("Erreur d'allocation de mémoire");
        fclose(file);
        exit(1);
    }

    // Offset remis au début du fichier pour charger le fichier
    rewind(file);

    // Charger le fichier dans le tableau
    size_t res = fread(fichier, 1, file_size, file);

    if (res != file_size) {
        perror("Lecture du fichier échouée");
        free(fichier);
        fclose(file);
        exit(1);
    }

    
    fclose(file);


    blueType=(unsigned char**)malloc(25*sizeof(unsigned char*));
    blueSpec=(unsigned char**)malloc(25*sizeof(unsigned char*));


    for(int i = 1; i <= 24; i++) {
        blueType[i] = (unsigned char*)malloc(30 * sizeof(unsigned char));
    }

    for(int i = 1; i <= 24; i++) {
        blueSpec[i] = (unsigned char*)malloc(30 * sizeof(unsigned char));
    }

    int octets=0;
    for(int i=1;i<=24;i++){
        for(int bp=0;bp<30;bp++){
        blueType[i][bp]= fichier[octets++];
    
        }
    }

    printf("octets = %d\n",octets);
    free(blueType);
    for(int i=1;i<=24;i++){
        for(int bp=0;bp<30;bp++){
        blueSpec[i][bp]= fichier[octets++];
    
        }
    }

    printf("octets = %d\n",octets);


}


// void checkc(){
//     if(objid==0 ||objid==pillartop||objid==panelwof||objid>=archtop1) carry_flag=true;

// }

// void dodrawc(){

// }
// void drawc(){
//  checkc();
//   if(!carry_flag) return;

//   dodrawc(); //OR C-section of piece below & to left
//   domaskb(); //Mask B-section of piece to left
// }  drawmc() on next pour l'instant


   
   // void drawb() ;//B-section of piece to left
   // void drawmb()
    void cont1(int blockd[]){
        IMAGE=blockd[];
        XCO=blockxco;
        YCO=Dy;
        add();
        //on met ff dans a

    }
    int drawd(){

        OPACITY= STA;
        if(objid==block){

            if (state< numblox){cont1(blockd[state])
            }
            else{//remettre y à 0 }

        }
        else if (objid!=panelwof){
            if(pieced[objid]){//;Do we need to mask this D-section?
                //mettre pieced[objid] dans a
            }


        }
        OPACITY=ORA;
        if(pieced[objid]==0){}
        IMAGE= pieced[objid];
        XCO= blockxco;
        YCO=Dy;
        add();
        return 255;//rn binaire ou ff

    }

    void drawmd(){
        if(objid==loose) return;
        drawloosed();

    }
   
    //void drawa() ;//A-section
    //void drawma();



void RedBlockSure(){
     //drawc() ;//C-section of piece below & to left
    // drawmc()
   
     //drawb() ;//B-section of piece to left
     //drawmb()
   
     drawd() ;//D-section
     drawmd()
     //drawa() ;//A-section
     //drawma()
    // drawfrnt() ;//A-section frontpiece (Note: This is necessary in case we do a layersave before we get to f.g. plane)
   

}

int getinitobj1(){
    if(blueType[1][yindex]&idmask==gate){
      return   initsettings[BlueSpec[1][yindex]];
      //bit de retenue à 1

    }
    else if(blueType[1][yindex]&idmask==loose){
        return 0;
    }
    else if(blueType[1][yindex]&idmask==flask){
        return BlueSpec[1][yindex]*32
        //bit de retenue mis

    }

}

int getobjbldr(){
    pile= blueType[1][yindex]&idmask;//recuperer apres avec pla
    getinitobj1();
    //reussi: on met dans state et on fait pla
    //raté on reprend blue spec


}


int getobjid1(int yindex){ //implanter linkmap
   
   if(inbuilder!=0) getobjbldr();

   state= blueSpec[1][yindex];

   if(blueType[1][yindex]&idmask== PRESSPLATE){
    if(linkmap[state]&idmask<2){
        return PRESSPLATE;
    } 
    return dpressplate;
   }if(blueType[1][yindex]&idmask== upressplate){
        if(linkmap[state]&idmask < 2){
            return upressplate;

        }
         state=0;
         return floor;

   }
   return;
}
int Gonull(){
    inmenu=0;
    if(inmenu==0) return getobjbldr();// a coder
    return space;




}

int getobjid(){
    if(SCRNUM==1) return Gonull();
    return getobjid1();
 
}

void SURE(){
 genCLS=1;//clear screen

 setback();

 //getprev(); get 3 rightmost blocks of screen to left Pas besoin pour l'instant

 
 calcblue("LEVEL1");//get blueprint base addr

 /* Draw 3 rows of 10 blocks (L-R, T-B)*/

    for(int rowno=2;rowno>=0;rowno--){ //0 = top row, 2 = bottom row
        Dy= BlockBot[rowno+1]//get Y-coord for bottom of D-section
        Ay=Dy-3;//& A-section

        yindex=Mult10[y];//block # (0-29)

        //recuperer etats et identifiant du block d'avant

        //getbelow();
    
        colno=0;           //0 = leftmost column, 9 = rightmost
        for(int colno=0;colno<10,colno++){
       
            XCO= colno*4;
            blockxco= colno*4; //get X-coord for A-section
            objid =getobjid();// car notre SCRNUM!=0

             RedBlockSure();//Redraw entire block

             PRECED= objid
             spreced= state

             yindex++;

        }

    //reste dessiner les parties des autres screens
 }
 }
 
 int *peelX= (int *)malloc(maxpeel*2*sizeof(int))
 void zeropeels(){
    peelX[0]=0;
    peelX[maxpeel]=0;
 }

 int  fredbuf[30];
 int  loorbuf[30];
 int  halfbuf[30];  
 int  wipebuf[30];
 int  movebuf[30];
 int objbuf[30];
 int topbuf[30];

 void zerored(){
    for(int y=29;y>0; y--){
     fredbuf[y]= 0;
     floorbuf[y]=0;
     halfbuf[y]=0;
     movebuf[y]= 0;
     objbuf[y]= 0;   
    }

    for(int y=9;y>0; y--){
        topbuf[y]= 0;
    }
   

 }



int BGset1=0;

 void DOGEN(){
    if(genCLS==0){
        if(BGset1!=1) return
        dummy[BGset1-1]=0;

    }else{
        //cls(); //clear screen avec des pixels noir
    }


 }

 int TABLE[2];

void setbgimg(){
    BANK= 3; // aux mem
    TABLE[0]=0;

    if(IMAGE&0x80){ //Bit 7: 0 = bgtable1, 1 = bgtable2
        //retourner bgtabe2 dans table+ 1


    }
    IMAGE= IMAGE&0x7F;
    //retourne bgtab2 dans table+1

}

void setimage(){

    return TABLE[ IMAGE&0x3F] // garder les 6 bit de poids faible 



}

void fastlay(){
    //passer de la memoir aux à la RAM


    image = setimage(); // renvoi donné de l'image 

    if(OPACITY==STA) fastlaySTA();
    smod= OPCODE[OPACITY];

    smXCO[1]=XCO;
    smWIDTH= image[0]; //largeur de l'image 
    smTOP= image[1];// hauteur de l'image 

    






}
 DRAWBACK(){
    if(bgX[0]==999) return; // si la première case est vide alors il n'y a aucune image dans le tableau car rempli dans l'ordre 
    
    for( int index=1; index<=maxback;index++){
        IMAGE= bgIMG[index];
        setbgimg(); //extraire BANK,TABLE,IMAGE pour hire call

        XCO= bgX[index];
        YCO=bgY[index];
        OPACITY= bgOP[index];

        fastlay();
    }

 }

 void drawall(){
    DOGEN(); //Do general stuff like cls

    //if(blackflag!=0) ZEROPEEL();
  
   
   // SNGPEEL(); "Peel off" characters (using the peel list we set up 2 frames ago) pas besoin pour l'nstant
   
    //ZEROPEEL(); //Zero just-used peel list
   
    DRAWWIPE() ;//Draw wipes
   
    DRAWBACK() ;//Draw background plane images
   
    //DRAWMID() ;//Draw middle plane images (& save underlayers to now-clear peel list)
   
    //DRAWFORE() ;//Draw foreground plane images
   
   // DRAWMSG() ;//Draw mess

 }
void DoSure(int VisScrn){//numero du screen qu'on souhaite dessiner, on le met à 1
    
 //SCRNUM = VisScrn; 

 int SCRNUM= 1;

 zerolsts();

 sure();

 zeropeels();
 zerored();

 drawall();

}