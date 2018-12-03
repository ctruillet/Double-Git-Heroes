#include <stdio.h>
#include "../include/fichier.h"
#include "../include/log.h"

/*
Derniere modification : 2018-12-02 17:28:04
Par : Clement
*/



//Vider le fichier si il existe déjà, sinon, le vider	
void init_fichier(const char * FICHIER, char * LOG){
  FILE* fichier = NULL;
  
  // Ouverture et création du fichier .dat
  fichier = fopen(FICHIER,"w+");
  fclose(fichier);
  
  //Ecriture dans log
  w_log(LOG,"Création du fichier .dat");
}

int w_fichier(FILE* fichier, Coord point){
	fprintf(fichier, "%f %f %f %f\n", get_t(point) , get_x(point), get_y(point) , get_z(point) );
	return 0;
	
}
