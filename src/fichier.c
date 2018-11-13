#include <stdio.h>
#include "include/fichier.h"
#include "include/position.h"


void init_fichier(){
	FILE* pos=NULL;
	pos = fopen("position.txt", "w+");
	fclose(pos);
}

void w_fichier(Coordonnees *point){
	FILE* pos= NULL;
	pos= fopen("position.txt","a");
	if(pos!=NULL){
		fscanf(pos, "%f %f %f",point->x);
	}
	fclose(pos);
}