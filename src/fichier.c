#include <stdio.h>
#include "fichier.h"

void init_fichier(){
	FILE* pos=NULL;
	pos = fopen("position.txt", "w+");
	fclose(pos);
}

void w_fichier(Coordonnees * point){
	FILE* pos= NULL;
	pos= fopen("position.txt","a");
	// tester si l'ouverture à réussi sinon ->log
	