#include <stdio.h>
#include "entrees.h"
#include "position.h"


 void init_position(Coordonnees *point, float *Tmax){
	  printf("Entrez la position initiale du point dans l'espace\nx?"\n);
	  scanf ("%f",point->x);
	  printf("y?\n");
	  scanf ("%f",point->y);
	  printf("f?\n");
	  scanf ("%f",point->z);
	  printf("Entrez les valeur de lorentz"\n);
 }
 
  void init_position(float *S, float *B, float *P){
	  printf("Entrez les valeur de lorentz\nσ?\n");
	  scanf("%f",S);
	  printf("ß?\n");
	  scanf("%f",B);
	  printf("ρ?\n");
	  scanf("%f",P);
 }

  void maj_vitesse(float *dt){
	  printf("Entrez la mise à jours de la vitesse\ndt=?");
	  scanf("%f",dt);
 }
 
 //reste à vérifier qu'il s'agit bien d'un nombre et appeler 2*log