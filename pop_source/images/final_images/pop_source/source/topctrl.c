//#include "global.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL2/SDL.h>
#include <stdbool.h>
#include <SDL2/SDL_image.h> 


#define maxpeel 46
#define Ffalling 10
#define numblox  2
#define gmaxval 47*4
#define gminval 0
#define block 20
#define panelwof 12
#define STA 2  // Opacité normale
#define ORA 1  // Opacité spécifique à dodrawc
#define DPRESSPLATE 5 //;down
#define PRESSPLATE 6 //;up

unsigned char *image_data;
const unsigned char loosed[] = {
    0x15, 0x2C, 0x15, 0x2D, 0x2D, 0x15, 0x15, 0x15, 0x2D, 0x2D, 0x2D
};

int dummy[]={maxpeel,maxpeel};
unsigned char blockd[2] = { 0x86, 0x86 };
const int initsettings[]={gmaxval,gminval};

unsigned char OPCODE[] = {
    0x31,  // and (oper), Y
    0x11,  // ora
    0x91,  // sta
    0x51,  // eor
    0x31,  // and
    0x91   // sta
};


const unsigned char pieced[] = {
    0x00, 0x15, 0x15, 0x15,
    0x15, 0x18, 0x19, 0x16,
    0x15, 0x00, 0x15, 0x00,
    0x17, 0x15, 0x2E, 0x4C
};

const int Mult10[16] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160};


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


int objid;
int BANK;




unsigned char idmask= 0x1F;
int Dy;
int XCO;
int YCO;
int IMAGE;
int OPACITY; //0-5
int state;
int blockxco;

#define space 0
#define upressplate 15
#define floor 1
#define dpressplate 5 //down
#define gate 4
#define loose 11
#define flask 10
int inbuilder=0;

/*Données blueprint*/
unsigned char **BlueType;
unsigned char **BlueSpec;
unsigned char *Table;
/*variable de image list*/
#define maxback 200
#define maxfore 100 //x
#define maxwipe 20 //x5
#define maxpeel 46 //x4
#define maxmid 46 //x11
#define maxobj 20 //x12
#define maxmsg 32 //x5

int peelX[maxpeel * 2];

 int bgX[maxback];
 int bgY[maxback]; 
 int bgIMG[maxback];
 int bgOP[maxback]; 
 int Ay;
 int yindex;
 int SCRNUM= 1;


/*variables initialisé dans zerolsts()*/
int  genCLS; 
int  wipeX;
int  midX;
int  objX;
int  fgX;
int  msgX;



void zerolsts(){//remet plusieurs variables à 0
    printf("je suis ds zerolsts\n");

 genCLS=0;
 wipeX=0;


    for(int i=0; i< maxback;i++){
    bgX[i]= 999;
    }
//midX=0;
//objX=0;
//fgX=0;
//msgX=0;

}


void addback(){

    printf("je suis dans ADDBACK\n");
    int x=0;
   if(bgX[maxback-1]!=999) return ;

   for(int i=1; i< maxback;i++){
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


int getloosey(){
    if (inbuilder==0){
        if(state>=0) return state;

        if(state&0x7F<Ffalling+1) { return state&0x7F; }
        else{ return 1;}
       
    }
    return 1;

}
void drawloosed(){
    int y= getloosey();
    if(loosed[y]==0) return;
    IMAGE= loosed[y];

    XCO=blockxco;
    YCO=Dy;
    OPACITY=STA;

    addback();
}


void setback(){
    printf("je suis dans SETBACK\n");
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


    BlueType=(unsigned char**)malloc(25*sizeof(unsigned char*)); // car 24 screens
    BlueSpec=(unsigned char**)malloc(25*sizeof(unsigned char*));


    for(int i = 1; i <= 24; i++) {
        BlueType[i] = (unsigned char*)malloc(30 * sizeof(unsigned char));
    }

    for(int i = 1; i <= 24; i++) {
        BlueSpec[i] = (unsigned char*)malloc(30 * sizeof(unsigned char));
    }

    int octets=0;
    for(int i=1;i<=24;i++){
        for(int bp=0;bp<30;bp++){
        BlueType[i][bp]= fichier[octets++];
    
        }
    }

    printf("octets = %d\n",octets);
   
    for(int i=1;i<=24;i++){
        for(int bp=0;bp<30;bp++){
        BlueSpec[i][bp]= fichier[octets++];
    
        }
    }

    
    printf("octets = %d\n",octets);
    free(fichier);

    printf("calclblue fini\n");


  
   
}



   
   
void cont1(unsigned char blockd){
    IMAGE=blockd;
    XCO=blockxco;
    YCO=Dy;
    addback();

}

void drawd(){

    OPACITY= STA;
    if(objid==block){

        if (state<numblox){ cont1(blockd[state]);
        }
        else{cont1(blockd[0]);
            }

    }
    else if (objid!=panelwof){
        if(pieced[objid]==0){
            return;
        }
    }
    OPACITY=ORA;
    if(pieced[objid]==0){}
    IMAGE= pieced[objid];
    XCO= blockxco;
    YCO=Dy;
    addback();
    

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
     drawmd();
     //drawa() ;//A-section
     //drawma()
    // drawfrnt() ;//A-section frontpiece (Note: This is necessary in case we do a layersave before we get to f.g. plane)
   

}
bool  carry= false;

int getinitobj1(){
    if(BlueType[1][yindex]&idmask==gate){
      carry=true;
      return   initsettings[BlueSpec[1][yindex]-1];
    

    }
    else if(BlueType[1][yindex]&idmask==loose){
        return 0;
    }
    else if(BlueType[1][yindex]&idmask==flask){
        carry=true;
        return BlueSpec[1][yindex]*32;

    }

    return 0;

}

int pile;
int getobjbldr(){
    pile= BlueType[1][yindex]&idmask;//recuperer apres avec pla
    state =getinitobj1();
    if(carry!=true) state= BlueSpec[1][yindex];

    return pile;

}


/*int getobjid1(int yindex){ //implanter linkmap
   
   if(inbuilder!=0) return getobjbldr();

   
        state= BlueSpec[1][yindex];

        if(BlueType[1][yindex]&idmask== PRESSPLATE){
            if(linkmap[state]&idmask<2){
                return PRESSPLATE;
            } 
        return dpressplate;
   }    if(BlueType[1][yindex]&idmask== upressplate){
            if(linkmap[state]&idmask < 2){
                 return upressplate;

        }
         state=0;
         return floor;

   }

   
}*/


int Gonull(){
    int inmenu=0;
    if(inmenu==0){return getobjbldr();}
    return space;

}

int getobjid(){
    if(SCRNUM==1) return Gonull();
}

void sure(){

 printf("je suis dans SURE\n");
 genCLS=1;//clear screen

 setback();

 //getprev(); get 3 rightmost blocks of screen to left Pas besoin pour l'instant

 
 calcblue("LEVEL1");//get blueprint base addr

 /* Draw 3 rows of 10 blocks (L-R, T-B)*/

    for(int rowno=2;rowno>=0;rowno--){  //0 = top row, 2 = bottom row
        Dy= BlockBot[rowno+1]; //get Y-coord for bottom of D-section
        Ay=Dy-3; //& A-section

        yindex=Mult10[rowno]; //block # (0-29)

        //recuperer etats et identifiant du block d'avant

        //getbelow();
    
           
        for(int colno=0;colno<10;colno++){//0 = leftmost column, 9 = rightmost
       
            XCO= colno*4;
            blockxco= colno*4; //get X-coord for A-section
            objid =getobjid();// car notre SCRNUM!=0

             RedBlockSure();//Redraw entire block

             //PRECED= objid
             //spreced= state

             yindex++;

        }

    //reste dessiner les parties des autres screens
 }
 }
 
 int peelX[maxpeel*2];

 void zeropeels(){
    peelX[0]=0;
    peelX[maxpeel]=0;
 }

 int  fredbuf[30];
 int floorbuf[30];
 int  loorbuf[30];
 int  halfbuf[30];  
 int  wipebuf[30];
 int  movebuf[30];
 int objbuf[30];
 int topbuf[30];

 void zerored(){
    printf("je suis dans ZERORED\n");
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

    printf("je suis dans DOGEN\n");
    if(genCLS==0){
        if(BGset1!=1) return;
        dummy[BGset1-1]=0;

    }else{
        //cls(); //clear screen avec des pixels noir
    }


 }


void setbgimg_bis(char ImgTab[15]){

    printf("je suis dans SETIMGBIS\n");
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
    Table= (unsigned char *)malloc(file_size * sizeof(unsigned char));

    if (Table == NULL) {
        perror("Erreur d'allocation de mémoire");
        fclose(file);
        exit(1);
    }

    // Offset remis au début du fichier pour charger le fichier
    rewind(file);

    // Charger le fichier dans le tableau
    size_t res = fread(Table, 1, file_size, file);

    if (res != file_size) {
        perror("Lecture du fichier échouée");
        free(Table);
        fclose(file);
        exit(1);
    }

    
    fclose(file);


   
}

void setbgimg(){ //retourner la bonne bgtable.
    printf("je suis dans SETBGIMG\n");
    BANK= 3; // aux mem
    

    if(IMAGE&0x80){ //Bit 7: 0 = bgtable1, 1 = bgtable2
        setbgimg_bis("IMG.BGTAB2.DUN");
        printf("BG2\n");
        
    }
    else{
        setbgimg_bis("IMG.BGTAB1.DUN");
        printf("BG1\n");


}
    

}

unsigned char *setimage(){
//voir si IMAGE change apres setbgtab



unsigned short bit_pds_faible;// première partie de l'adresse
unsigned short bit_pds_fort; //2eme partie 
unsigned short pos_temp;// combinaison bit poids fort et faible
unsigned short pos_final; // soustraction pos_temp - adresse ou est chargé le fichier

unsigned char pixel;

int nb_oct_par_ligne=0; 
int nb_lines =0;     // Nombre de lignes


    printf("image num  %u \n" ,IMAGE&0x3F);
    bit_pds_faible= Table[2*(IMAGE&0x3F) +1];
    bit_pds_fort= Table[2*(IMAGE&0x3F) +2];
    printf("IMAGE %d\n",IMAGE&0x3F);
    


    printf("bits de poids faible: %02X\n", bit_pds_faible);
    printf("bits de poids fort:  %02X\n",bit_pds_fort);

    pos_temp = (bit_pds_fort << 8) | bit_pds_faible; //combiner les 2 adresse

    printf("position temp vant soustraction: %02X\n", pos_temp);

    pos_final=  pos_temp - 0x6000; 

    printf("pos final en hexa %04X\n", pos_final);
    printf("pos final en deci %u\n", pos_final);

// lire nombre octets par lgnes et nb lignes
    nb_oct_par_ligne= Table[pos_final];
    nb_lines= Table[pos_final+1];
    printf("nb_oct_par_ligne %u\n", nb_oct_par_ligne);
    printf(" nb_lines %u\n", nb_lines);
    printf("fichier[pos_final] %u\n",Table[pos_final]);
 
    image_data= (unsigned char *)malloc((nb_lines*nb_oct_par_ligne)*sizeof(unsigned char));

    memcpy(image_data,Table+ pos_final,nb_oct_par_ligne*nb_lines);

    

}

void fastlay(SDL_Window *window,SDL_Renderer *renderer,SDL_Surface*  screenshot){
    printf("je suis dans FASTLAY\n");
    //passer de la memoir aux à la RAM


    unsigned char *image_data = setimage(); // renvoi donné de l'image 

    //if(OPACITY==STA) fastlaySTA();
    int smod= OPCODE[OPACITY];

    int smXCO=XCO;
    int smYCO= YCO;
    int smWIDTH= image_data[0]; //largeur de l'image 
    int smTOP= image_data[1];// hauteur de l'image 

    int pos_ligne = 2+ ((smTOP - 1) * smWIDTH);

    


        /*DESSINER L'IMAGE */


        // Pour chaque ligne de l'image
        for (int line_num = smTOP - 1; line_num >= 0; line_num--) {
            
            // Pour chaque octet de la ligne
            for (int byte = 0; byte < smWIDTH; byte++) {
                unsigned char pixel = image_data[pos_ligne];
                pos_ligne = pos_ligne + 1;

                // Pour chaque bit dans l'octet
                for (int bit = 0; bit < 7; bit++) {
                    if (pixel & (1 << (bit))) {
                        // Dessiner le pixel sur la surface (blanc pour pixel allumé )
                        SDL_Rect rect = { smXCO, smYCO, 1, 1 };
                        SDL_FillRect(screenshot, &rect, SDL_MapRGB(screenshot->format, 255, 255, 255));
                        smXCO++;
                    } else {
                        // Dessiner le pixel éteint (noir)
                        SDL_Rect rect = { smXCO, smYCO, 1, 1 };
                        SDL_FillRect(screenshot, &rect, SDL_MapRGB(screenshot->format, 0, 0, 0));
                        smXCO++;
                    }
                }
            }

            pos_ligne = pos_ligne - (2 * smWIDTH);
            smYCO++;
            smXCO=XCO;

        }

          // Mise à jour de la fenêtre SDL avec la surface
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, screenshot);
    if (texture == NULL) {
        printf("Erreur lors de la création de la texture: %s\n", SDL_GetError());
        return;
    }

    // Effacer le renderer
    SDL_RenderClear(renderer);

    // Dessiner la texture
    SDL_RenderCopy(renderer, texture, NULL, NULL);

    // Mettre à jour l'affichage
    SDL_RenderPresent(renderer);

    SDL_DestroyTexture(texture); // Libérer la texture


   
}

 void DRAWBACK(){
    printf("je suis dans DRAWBACK\n");
    if(bgX[1]==999) return; // si la première case est vide alors il n'y a aucune image dans le tableau car rempli dans l'ordre 
    printf("JE RETOURNE");

    /*********************************
     *         SDL
     * 
     * *******************************/

 // Initialisation de SDL
     if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Erreur d'initialisation de SDL: %s\n", SDL_GetError());
        return;
    }

    // Créer une fenêtre SDL
    SDL_Window *window = SDL_CreateWindow("Affichage Image avec SDL",
                                          SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                          39*7, 192, SDL_WINDOW_SHOWN);
            
     if (window == NULL) {
        printf("Erreur  %s\n", SDL_GetError());
        SDL_Quit();
     
        return ;
     }

     // Créer un renderer pour dessiner dans la fenêtre 
     SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
     if (renderer == NULL) {
        printf("Erreur  %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return ;
     }


        // Créer une SDL_Surface pour y dessiner l'image
        SDL_Surface*  screenshot = SDL_CreateRGBSurface(0, 39*7, 192, 32, 0, 0, 0, 0);
        if (!screenshot) {
            printf("Erreur  %s\n", SDL_GetError());
            SDL_DestroyRenderer(renderer);
            SDL_DestroyWindow(window);
            SDL_Quit();
            return ;
        }

    /*********************************
     *        FIN SDL
     * 
     * *******************************/
        
    for( int index=1; index<=65/*maxback*/;index++){
        IMAGE= bgIMG[index];
        setbgimg(); //extraire BANK,TABLE,IMAGE pour hire call

        XCO= bgX[index];
        YCO=bgY[index];
        OPACITY= bgOP[index];

        fastlay(window,renderer,screenshot);
    }

    SDL_Delay(20000);

 }

 void drawall(){
    printf("je suis dans DRAWALL\n");
    DOGEN(); //Do general stuff like cls

    //if(blackflag!=0) ZEROPEEL();
  
   
   // SNGPEEL(); "Peel off" characters (using the peel list we set up 2 frames ago) pas besoin pour l'nstant
   
    //ZEROPEEL(); //Zero just-used peel list
   
    //DRAWWIPE() ;//Draw wipes
   
    DRAWBACK() ;//Draw background plane images
   
    //DRAWMID() ;//Draw middle plane images (& save underlayers to now-clear peel list)
   
    //DRAWFORE() ;//Draw foreground plane images
   
   // DRAWMSG() ;//Draw mess

 }



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

    for(int i=1; i<=10;i++){

        printf("bgIMG %d %d\n ", i,bgIMG[i] );
        printf("bgX %d %d\n ", i,bgX[i] );
        printf("bgY %d %d\n ", i,bgY[i] );




    }

    return 1;

}
