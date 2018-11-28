#include <stdio.h>
#include <stdlib.h>
#include "include/fichier.h"

void lol(int *a){
	scanf("%d",a);
}
	
void init_fichier(){
	FILE* pos=NULL;
	pos = fopen("Lorentz.dat", "w+");
	fclose(pos);// mettre à la fin du main
}

void w_fichier(Coordonnees *point){
	FILE* pos= NULL;
	pos= fopen("Lorentz.dat","a");
	if(pos!=NULL){
		fprintf(pos, "%f\n%f\n%f\n",point->x, point->y, point->z);
	}
	fclose(pos);// mettre à la fin du main
}

int main(int argc, char*argv[]){
	int c;
	lol(&c);
	printf("%d",lol(&c));
	return 0;
}
//fksjfskfjsek
