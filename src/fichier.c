#include <stdio.h>
#include "../include/fichier.h"
#include "../include/log.h"

//Vider le fichier si il existe déjà, sinon, le vider	
void init_fichier(const char * FICHIER, char * LOG){
  FILE* fichier = NULL;
  
  // Ouverture et création du fichier .dat
  fichier = fopen(FICHIER,"w+");
  fclose(fichier);
  
  //Ecriture dans log
  w_log(LOG,"Création du fichier .dat");
}

//Ecrire dans le fichier DATA ouvert au préalable
int w_fichier(FILE* fichier, Coordonnees * point){
	fprintf(fichier, "%f %f %f %f\n", (*point).t , (*point).x, (*point).y , (*point).z );
	return 0;
	
}