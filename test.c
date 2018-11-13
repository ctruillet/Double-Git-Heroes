#include <stdio.h>
#include <stdlib.h>
#include "include/fichier.h"

void lol(int *a){
	scanf("%d",a);
}
	
void init_fichier(){
	FILE* pos=NULL;
	pos = fopen("position.txt", "w+");
	fclose(pos);
}	

void w_fichier(Coordonnees *point){
	FILE* pos= NULL;
	pos= fopen("position.txt","a");
	if(pos!=NULL){
		//fprintf(pos, "%f\n%f\n%f\n%f\n",point->t,point->x,point->y,point->z);
		fprintf(pos, "%f",point->t);
		fprintf(pos, "%f",point->x);
		fprintf(pos, "%f",point->y);
		fprintf(pos, "%f",point->z);
	}
	fclose(pos);
}

int main(int argc, char*argv[]){
	init_fichier();
	Coordonnees point={0, 3, 2, 1};
	w_fichier(&point);
	return 0;
}
//fksjfskfjsek
