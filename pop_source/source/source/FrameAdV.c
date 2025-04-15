#include "Global.h"

/****************************************
 *         Declarations
 ****************************************/

 int Dy;
 int Ay;
 int yindex;
 int blockxco;
 int objid;
 int state;

 const int initsettings[]={gmaxval,gminval};
 bool  carry= false;
 int pile;
 int gateposn;


 /*********************************************
 *       Draw B-section of piece to left
 **********************************************/



 void drawb(){

    if(objid==block) return; //B-section hidden by solid block
    if(PRECED==space){

        if(spreced>=numbpans+1){return;}
        else if(spaceb[spreced]==0){return;}
        else{
            IMAGE= spaceb[spreced];
            YCO=spaceby[spreced] + Ay; //clearcary avant donc on ajoute pas 1, parti :cont
            XCO=blockxco;
            OPACITY=ORA;
            addback();
        }

    }
    else if(PRECED==floor){
        if(spreced>=numbpans+1){
            if(floorb[spreced]==0){return;}
            else{ IMAGE=floorb[spreced];
            
                YCO=floorby[spreced] + Ay;
                XCO=blockxco;
                OPACITY=ORA;
                addback();

            }
        }else{
            if(floorb[0]==0){return;}
            else{ 
                IMAGE=floorb[0];
                YCO=floorby[0] + Ay;
                XCO=blockxco;
                OPACITY=ORA;
                addback();

            }

        }

    }
    else if(PRECED==block){

        if(spreced<numblox){
           IMAGE= blockb[spreced];//:cont1
           YCO= pieceby[PRECED]+Ay;
           XCO=blockxco;
           OPACITY=ORA;
           addback();
        }else{
            IMAGE= blockb[0];
            YCO= pieceby[PRECED]+Ay;
           XCO=blockxco;
           OPACITY=ORA;
           addback();
        }


    }
    else if(pieceb[PRECED]==0){//:stripe * Add stripe (palace bg set only)

        if(BGset1!=1){return;} //pal
        else if(bstripe[PRECED]==0){return;}//str1
             
             else{
                IMAGE=bstripe[PRECED];
                carry=true;
                YCO= Ay-32;
                XCO=blockxco;
                OPACITY=ORA;
                addback();
             }




    } else if(objid==panelb0){ //:panel * Special panel handling
        if(spreced>=numpans){return;}
        else if (panelb[spreced] !=0){
            IMAGE= panelb[spreced];
            YCO=pieceby[PRECED]+Ay;
            XCO=blockxco;
            OPACITY=ORA;
            addback();
        }else{return;}

    } else{//* draw regular B-section :cont1
        IMAGE=pieceb[PRECED];
        YCO=pieceby[PRECED]+Ay;
        XCO=blockxco;
        OPACITY=ORA;
        addback();

    }


 }


/*********************************************
 *      D R A W   G A T E   " C "
 **********************************************/

 void drawgatec(int colno){
    YCO=Dy;
    IMAGE=gatecmask;
    OPACITY=and;
    addback();
    if(SBELOW[colno]<gmaxval){

        gateposn=SBELOW[colno]/4;

        int y = -(gateposn & 0xF8);  

        IMAGE= gate8c[gateposn+y];

        OPACITY=ORA;

        addback();

    }

    gateposn=gmaxval/4;

    int negation = -(gateposn & 0xF8);  

    IMAGE= gate8c[gateposn+negation];

    OPACITY=ORA;

    addback();

 }

 /*********************************************
 *       drawmc, D R A W  M O V A B L E  ' C '
 **********************************************/

void drawmc(int colno){
    if(objid==space||objid==panelwof||objid==pillartop){//;is there a piece here?

       if( BELOW[colno]!=gate) return;
       //that piece is a gate
       drawgatec(colno);

    }
    return; //sera couvert par la section A


}


 /****************************************
 *         DRAWC et ses 3 fonctions
 ****************************************/

//*  Mask B-section of piece to left
 void domaskb(){
   if(maskb[PRECED]==0) return;
   IMAGE= maskb[PRECED];

   YCO=Dy;
   OPACITY= and;
   addback();

 }

//Draw C-section of piece below & to left
void dodrawc(int colno){


    if(BELOW[colno]== block) {//objid of piece below & to left
       if( SBELOW[colno]<numblox){//block ou pas block, l'ajouter si c'est le cas 
       IMAGE= blockc[SBELOW[colno]];
       XCO=blockxco;
       YCO=Dy;
       OPACITY= ORA;
       addback();

       }

    } 
    else{
        if(piecec[BELOW[colno]]==0) return;//pas de section c
        if(piecec[BELOW[colno]]==panelc0){
            //* Special panel handling
           if(SBELOW[colno]>=numpans ){ //num of different panel
            return;

        }else{
           if(panelc[SBELOW[colno]]!=0){
            IMAGE= panelc[SBELOW[colno]];
            XCO=blockxco;
            YCO=Dy;
            OPACITY= ORA;
            addback();
            
           }
           else return;
        }
    } 

    IMAGE=piecec[BELOW[colno]];
    XCO=blockxco;
    YCO=Dy;
    OPACITY= ORA;
    addback();
}
}

void checkc(){
    if(objid==0||objid==pillartop||objid==panelwof||objid>=archtop1){//section C visible
        carry=true;
        return;
    }
    else{ carry=false;
    return;
}

}



void drawc(int colno){
    checkc();
    if(carry== false) return;
    dodrawc(colno);
    domaskb();

}
/****************************************
 *         GETBELOW
 ****************************************/



/*ON ne gere que les cas avec l'ecran du bas null*/
void getbelow(int rowno){
    if(rowno<2){//* "ONSCREEN": Looking below top or middle row
        BELOW[0]= PREV[rowno+1];
        SBELOW[0]= sprev[rowno+1];
        carry=false;
        int  y=yindex;
        for(int xsave=1;xsave<10;xsave++){
           
            getobjid(y+10);
            BELOW[xsave]=//ce que va renvouer getobjid
            SBELOW[xsave]= state;
            y++;
        }
        return;
    
    }
    //null screen
    for(int i= 1;i<10;i++){

        BELOW[i]=1;
    }

    if(level==12){BELOW[0]= space;}
    else{ BELOW[0]=block;}


}

/****************************************
 *         GetPREV
 ****************************************/

 /*Pour l'instant, on cherche à dessiner les écran indépendemment des screens droite/gauche/bas/haut
 Donc on ne traduit que la partie de getprev qui gere le cas avec le screen d'avant null*/

 void getprev(){ 
    PREV[0]=block; 
    PREV[1]=block;
    PREV[2]=block;
    sprev[0] =0;
    sprev[1] =0;
    sprev[2] =0;
 }
/****************************************
 *         GONULL
 ****************************************/

int Gonull(){
    int inmenu=0;
    if(inmenu==0){return getobjbldr();}
    return space;

}


/****************************************
 *         GETOBJID1
 ****************************************/

int getobjid1(int yindex){ //implanter linkmap
   
   if(inbuilder!=0) return getobjbldr();

   
        state= BlueSpec[1][yindex];

        if(BlueType[1][yindex]&idmask== PRESSPLATE){
            if(LINKMAP[state]&idmask<2){
                return PRESSPLATE;
            } 
        return dpressplate;
   }    if(BlueType[1][yindex]&idmask== upressplate){
            if(LINKMAP[state]&idmask < 2){
                 return upressplate;

        }
         state=0;
         return floor;

   }

   
}


/****************************************
 *         GETOBJBLDR
 ****************************************/

int getobjbldr(){
    pile= BlueType[1][yindex]&idmask;//recuperer apres avec pla
    state =getinitobj1();
    if(carry!=true) state= BlueSpec[1][yindex];

    return pile;

}

/****************************************
 *         GETINITOBJ1
 ****************************************/

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
/****************************************
 *         GETLOOSEY
 ****************************************/

int getloosey(){
    if (inbuilder==0){
        if(state>=0) return state;

        if(state&0x7F<Ffalling+1) { return state&0x7F; }
        else{ return 1;}
       
    }
    return 1;

}


 /****************************************
 *         DRAWLOOSED
 ****************************************/

 void drawloosed(){
    int y= getloosey();
    if(loosed[y]==0) return;
    IMAGE= loosed[y];

    XCO=blockxco;
    YCO=Dy;
    OPACITY=STA;

    addback();
}


/****************************************
 *         DRAWD
 ****************************************/

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




/****************************************
 *         DRAWMD
 ****************************************/

void drawmd(){
    if(objid==loose) return;
    drawloosed();

}

/****************************************
 *         REDBLOCKSURE
 ****************************************/

void RedBlockSure(int colno){
    drawc(colno) ;//C-section of piece below & to left
    drawmc(colno);
  
    drawb() ;//B-section of piece to left
    //drawmb()
  
    drawd() ;//D-section
    drawmd();
    //drawa() ;//A-section
    //drawma()
   // drawfrnt() ;//A-section frontpiece (Note: This is necessary in case we do a layersave before we get to f.g. plane)
  

}

/****************************************
 *         GETOBJID
 ****************************************/


int getobjid(int yindex){
    if(SCRNUM==0) return Gonull();
    getobjid1(yindex);
}


/****************************************
 *         SETBACK
 ****************************************/


void setback(){
    printf("je suis dans SETBACK\n");
    addback();// pas vraiment, ptr de fonction vers add back pour la prochaine fois qu'on appelle add
}

/****************************************
 *         SURE
 ****************************************/

void sure(){

    printf("je suis dans SURE\n");
    genCLS=1;//clear screen
   
    setback();
   
    getprev(); //get 3 rightmost blocks of screen to left Pas besoin pour l'instant
   
    
    calcblue("LEVEL2");//get blueprint base addr en fonction de SCRNUM
   
    /* Draw 3 rows of 10 blocks (L-R, T-B)*/
   
       for(int rowno=2;rowno>=0;rowno--){  //0 = top row, 2 = bottom row
           Dy= BlockBot[rowno+1]; //get Y-coord for bottom of D-section
           Ay=Dy-3; //& A-section
   
           yindex=Mult10[rowno]; //block # (0-29)
           PRECED= PREV[rowno];
           spreced= sprev[rowno];//pour recuperer l'etat du block d'avant
   
           getbelow(rowno);
       
              
           for(int colno=0;colno<10;colno++){//0 = leftmost column, 9 = rightmost
          
               XCO= colno*4;
               blockxco= colno*4; //get X-coord for A-section
               objid =getobjid(yindex);// car notre SCRNUM!=0
   
                RedBlockSure(colno);//Redraw entire block,colno pour dodrawc
   
                PRECED= objid;
                spreced= state;
   
                yindex++;
   
           }
   
       //reste dessiner les parties des autres screens
    }
    }