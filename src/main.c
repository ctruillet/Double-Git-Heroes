#include <stdio.h>
#include "../include/entrees.h"
#include "../include/fichier.h"
#include "../include/gnuplot.h"
#include "../include/position.h"
#include "../include/log.h"



int main(int argc, char *argv[]){
	char LOG[128]; //Création d'une variable contenant le nom du fichier .log 
	
	crea_log(LOG);
	
	w_log(LOG,"La fonction main s'est bien executée");
	
	printf("Ok\n");
	return(0);
}