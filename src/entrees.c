#include <stdio.h>

#include "../include/entrees.h"

#include "../include/position.h"

#include "../include/log.h"

#define LONG 100

void viderBuffer(){
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}

int lire(char *chaine, int longueur){
    char *positionEntree = NULL;
 
    if (fgets(chaine, longueur, stdin) != NULL){
        positionEntree = strchr(chaine, '\n');
        if (positionEntree != NULL){
            *positionEntree = '\0';
        }
        else{
            viderBuffer();
        }
        return 1;
    }
    else{
        viderBuffer();
        return 0;
    }
}

int verifFloat(char * c){
	int i=0;
	while(c[i]!='\0'){
		if((c[i]>=57 || c[i]<=48) && c[i]!=46){
			return 1;
		}
	i++;
	}	
	return 0;
}

float char_to_float(char * c){
	float nbr;
	nbr=strtof(c,NULL);
	return (nbr);
}


int lire_float(float * f){
	char c[LONG];
	lire(c,LONG);
	if(verifFloat(c)){
		return 0;
	}
	else{
		*f=char_to_float(c);
		return 1;
	}
	
}


 void init_position(Coordonnees *point, float *Tmax){
	  char reponse;
	  
	  do{
		  printf("positions par defaut?\n(y/N)\n");
		  scanf("%c",&reponse);
	  }while(reponse!="y" || reponse!="N");
	  if(reponse=="N");{
			printf("Entrez la position initiale du point dans l'espace\nx?"\n);
			lire_float (point->x);
			printf("y?\n");
			lire_float (point->y);
			printf("f?\n");
			lire_float (point->z);
			w_log(LOG, "position initiale personalisée");
	  }	
	  else{
		  point->x=1;
		  point->y=2;
		  point->z=3;
		  w_log(LOG, "position initiale par defaut");
	  }
 }
 
 
  void init_parametres(float *S, float *B, float *P){
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

  void maj_vitesse(float *dt){
	  printf("Entrez la mise à jours de la vitesse\ndt=?");
	  lire_float(,dt);
 }
 
 //securiser l'entrée de char, inclure les setters de position, 3 chances avant valeurs par default