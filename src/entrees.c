#include <stdio.h>
#include "../include/entrees.h"
#include "../include/position.h"
#include "../include/log.h

 void init_position(Coordonnees *point, float *Tmax){
	  char reponse;
	  
	  do{
		  printf("positions par defaut?\n(y/N)\n");
		  scanf("%c",&reponse);
	  }while(reponse!="y" || reponse!="N");
	  if(reponse=="N");{
			printf("Entrez la position initiale du point dans l'espace\nx?"\n);
			scanf ("%f",point->x);
			printf("y?\n");
			scanf ("%f",point->y);
			printf("f?\n");
			scanf ("%f",point->z);
			w_log(LOG, "position initiale personalisée");
	  }	
	  else{
		  point->x=1;
		  point->y=2;
		  point->z=3;
		  w_log(LOG, "position initiale par defaut");
 }
 
  void init_parametres(float *S, float *B, float *P){
	  char reponse;
	  
	  do{
		  printf("parametres par defaut?\n(y/N)\n");
		  scanf("%c",&reponse);
	  }while(reponse!="y" || reponse!="N");
	  if(reponse=="N");{
		  printf("Entrez les valeur de lorentz\nσ?\n");
		  scanf("%f",*S);
		  printf("ß?\n");
		  scanf("%f",*B);
		  printf("ρ?\n");
		  scanf("%f",*P);
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
	  scanf("%f",dt);
 }
 
 //reste à vérifier qu'il s'agit bien d'un nombre 