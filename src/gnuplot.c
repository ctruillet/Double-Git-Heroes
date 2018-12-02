#include <stdio.h>
#include <stdlib.h>
#include "../include/log.h"
#include "../include/gnuplot.h"

/*
Derniere modification : 2018-12-02 23:14:08
Par : Clement
*/


/*
	Cette librairie appelle le fichier .sh qui lance gnuplot avec les bons parametres.
*/
  
//Fonction qui appelle le bon fichier de parametres en fonction du mode
//En fait, on a ici un fichier .sh par attracteur pour le titre du graphe.
//Sinon, il n'y a aucune difference entre eux
void trace_courbe(int mode, const char * FICHIER, char * LOG){
	
	w_log(LOG, "Ouverture de Gnuplot.");

	switch(mode){
		case 0:
			system("./lorenz.sh");
			break;
		case 1:
			system("./vanderpol.sh");
			break;
		case 2:
			system("./rossler.sh");
			break;
		default:
			w_log(LOG, "[ERROR] Echec de l'ouverture de Gnuplot");
	}
	
}
