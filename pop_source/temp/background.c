#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
int main() {
    FILE *file;

    unsigned short bit_pds_faible;// première partie de l'adresse
    unsigned short bit_pds_fort; //2eme partie 
    unsigned short pos_temp;// combinaison bit poids fort et faible
    unsigned short pos_final; // soustraction pos_temp - adresse ou est chargé le fichier

    unsigned char pixel;

    int nb_oct_par_ligne=0; 
    int nb_lines =0;     // Nombre de lignes
   
    

    // Ouvre le fichier en mode binaire
    file = fopen("IMG.BGTAB1.DUN", "rb");

    
    if (file == NULL) {
        perror("Erreur d'ouverture du fichier");
        return 1;
    }

    //déplace l'offset à la fin deu fichier
    fseek(file, 0, SEEK_END);

    // renvoie la position de l'offset et donc la taille du fichier
    size_t  file_size = ftell(file);

    if (file_size == -1) {
        perror("Erreur lors de la lecture de la taille du fichier");
        fclose(file);
        return 1;
    }

   //tableau qui va contenir le fichier 
    unsigned char *fichier = (unsigned char*)malloc(file_size*sizeof(unsigned char));

    if (fichier == NULL) {
        perror("Erreur d'allocation de mémoire");
        fclose(file);
        return 1;
    }

    // offset remi au debut du fichier 
    rewind(file);

     //charger le fichier dans le tableau 
    size_t res =fread(fichier,1, file_size, file);

    if(res!=file_size){
        perror("lecture du fichier no");
        free(fichier);
        fclose(file);
        return 1;
    }

    // Ferme le fichier
    fclose(file);

    //nb d'image +1 qui corresond au premier fichier
    unsigned char nb_image= fichier[0];

    printf("nb image:  %u\n", nb_image);

    
// commencer à lire les images
   for (int i=0; i<4; i++){

        printf("image num  %u \n" ,i);
        bit_pds_faible= fichier[2*i +1];
        bit_pds_fort= fichier[2*i +2];


        printf("bits de poids faible: %02X\n", bit_pds_faible);
        printf("bits de poids fort:  %02X\n",bit_pds_fort);

        pos_temp = (bit_pds_fort << 8) | bit_pds_faible; //combiner les 2 adresse

        printf("position temp vant soustraction: %02X\n", pos_temp);

        pos_final=  pos_temp - 0x6000; 

        printf("pos final en hexa %04X\n", pos_final);
        printf("pos final en deci %u\n", pos_final);

    // lire nombre octets par lgnes et nb lignes
        nb_oct_par_ligne= fichier[pos_final];
        nb_lines= fichier[pos_final+1];
        printf("nb_oct_par_ligne %u\n", nb_oct_par_ligne);
        printf(" nb_lines %u\n", nb_lines);
        printf("fichier[pos_final] %u\n",fichier[pos_final]);
     
       

    unsigned short pos_ligne= pos_final+2+((nb_lines-1)*nb_oct_par_ligne) ; 

    // Pour chaque ligne de l'image
       for (int line_num = nb_lines-1; line_num >=0; line_num--) {
          
        // Affiche les pixels de la ligne
           for (int byte = 0; byte < nb_oct_par_ligne; byte++) {
               pixel = fichier[pos_ligne];
               pos_ligne=pos_ligne +1;
               for (int bit = 0; bit < 7; bit++) {
                // 1 pour pixel allumé, 0 our celui qui est eteint
                   if (pixel & (1 << ( bit))) {
                      printf("#");  
                      } else {
                      printf("."); 
             }
         }
          
     }

     pos_ligne= pos_ligne - (2*nb_oct_par_ligne);
     printf("\n");
    }
   }
   
    return 0;

}