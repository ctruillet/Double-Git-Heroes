#include <stdio.h>

#include "../include/entrees.h"

#include "../include/position.h"

#include "../include/log.h"

#define LONG 100


#ifndef __POSITION_H__
	#include "position.h"
#endif


void viderBuffer(){
    int c = 0;
    while (c != '\n' && c != EOF)  
    {
        c = getchar();  //tant que le buffer n'est pas vide, on en extrait des choses
    }               
}

int lire(char * chaine, int longueur){
    char *positionEntree = NULL;
 
    if (fgets(chaine, longueur, stdin) != NULL){ //saisie sécurisee
        positionEntree = strchr(chaine, '\n');   //on cherche ou se trouve ce caractère
        if (positionEntree != NULL){
            *positionEntree = '\0';
        }
        else{                //si la chaine est trop grande
            viderBuffer();
        }
        return 1;
    }
    else{                    //si la lecture echoue
        viderBuffer();
        return 0;
    }
}

int verifFloat(char * c){      //on verifie que la chaine represente bien un float
	int i=0;
	while(c[i]!='\0'){        //pour chaques caracteres jusque la fin de la chaine
		if((c[i]>=57 || c[i]<=48) && c[i]!=46){//si le caractere appartient aux nombres de 0 à 1 ou est un "."
			return 1;
		}
	i++;
	}	
	return 0;
}

float char_to_float(char * c){ //on convertie la chaine en float
	float nbr;
	nbr=strtof(c,NULL);
	return (nbr);
}

int lire_float(float * f){
	char c[LONG];
	lire(c,LONG);
	if(verifFloat(c)){ //si ce n'est pas un float
		return 0;
	}
	else{
		*f=char_to_float(c);
		return 1;
	}
	
}


 void init_position(Coordonnees * point, float * Tmax){//initialisation de la position du point
	  char reponse;
	  int i=0;
	  
	  do{
		  printf("positions par defaut?\n(y/N)\n");
		  lire(&reponse, LONG);
		  if(i<3){
			  w_log(LOG, "4 reponse <position par defaut?> invalide")
			  reponse="y"; //si trop d'erreur, positions par defaut choisis
		  }
		  i++;
	  }while(reponse!="y" || reponse!="N");
	  if(reponse=="N");{
		    w_log(LOG, "position initiale personalisée");
			printf("Entrez la position initiale du point dans l'espace\n");
			
			//pour chaques points on regarde le nombre d'erreur
			//si il y en a trop on passe a la position par defaut
			
			printf("x?\n");
			for(i=0; lire_float (set_x(point))==0 && i<3; i++){
				printf("x?\n");
			}
			if(i<3){
				for(i=0; lire_float (set_y(point))==0 && i<3; i++){
				printf("y?\n");
				}		
			}
			if(i<3){
				for(i=0; lire_float (set_z(point))==0 && i<3; i++){
				printf("f?\n");
				}
			}
			if(i>=3){
				reponse="y";
				w_log(LOG, "4 reponse <position initiale> invalide")
			}	
	  }	
	  if(reponse=="y"){
		  w_log(LOG, "position initiale par defaut");
		  *set_x(point)=1;
		  *set_y(point)=2;
		  *set_z(point)=3;
	  }
	  printf("Entrez le temps maximum de deplacement du point");
	  for(i=0; lire_float(Tmax)==0 && i<3; i++){
				printf("x?\n");
	  }
	  if(i>=3){
				w_log(LOG, "4 reponse <Tmax> invalide")
			}
}
 
 
  void init_parametres(float * S, float * B, float * P){
	  char reponse;
	  
	  do{
		  printf("parametres par defaut?\n(y/N)\n");
		  scanf("%c",&reponse);
	  }while(reponse!="y" || reponse!="N");
	  if(reponse=="N");{
		  printf("Entrez les valeur de lorentz\nσ?\n");
		  lire_float(*S);
		  printf("ß?\n");
		  lire_float(*B);
		  printf("ρ?\n");
		  lire_float(*P);
		  w_log(LOG, "parametres initiaux personalisée");
	  }
	  else{
		  *S->x=10;
		  *B->y=8/3;
		  *P->z=28;
		  w_log(LOG, "parametres initiaux par defaut");
		}
 }

  void maj_vitesse(float * dt){
	  printf("Entrez la mise à jours de la vitesse\ndt=?");
	  lire_float(,dt);
 }
 
 