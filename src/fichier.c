#include <stdio.h>
#include "../include/fichier.h"
#include "../include/log.h"


void init_fichier(const char * FICHIER, char * LOG){
  FILE* fichier = NULL;
  
  // Ouverture et création du fichier .dat
  fichier = fopen(FICHIER,"w+");
  fclose(fichier);
  
  //Ecriture dans log
  w_log(LOG,"Création du fichier .dat");
}


int w_fichier(const char * FICHIER, Coordonnees * point){

  FILE* fichier = NULL;

  fichier = fopen(FICHIER,"a");

  if (fichier != NULL) // On peut lire et écrire dans le fichier
    {
        fprintf(fichier, "%f %f %f %f\n", (*point).t , (*point).x, (*point).y , (*point).z );
        fclose(fichier);
        return 0;
    }
    else // On retourne l'erreur à la fonction main qui arrete l'execution
    {
        return 1;
    }

}

int w_fichier_test(FILE* fichier, Coordonnees * point){
	fprintf(fichier, "%f %f %f %f\n", (*point).t , (*point).x, (*point).y , (*point).z );
	return 0;
	
}