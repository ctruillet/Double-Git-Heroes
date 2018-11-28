#include <stdio.h>
#include "../include/fichier.h"
#include "../include/position.h"


void init_fichier(){
	FILE* pos=NULL;
	pos = fopen("../data/Lorentz.dat", "w+");
	fclose(pos);//à enlever
}

void w_fichier(Coordonnees *point){
	FILE* pos= NULL;
	pos= fopen("Lorentz.dat","a");
	if(pos!=NULL){
		fprintf(pos, "%f\n%f\n%f\n",point->x, point->y, point->z);
	}
	fclose(pos);//à mettre à la fin du main
}

void ​read_fichier​(​Coordonnees​ * point, ​float ​temps){
	FILE* pos= NULL;
	pos= fopen("Lorentz.dat","a");
	if(pos!=NULL){
		scanf(pos, "%f %f %f %f",temps, point->x, point->y, point->z);
	}
}