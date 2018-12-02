#include <stdio.h>
#include <stdlib.h>
#include "../include/log.h"
#include "../include/gnuplot.h"

/*
Derniere modification : 2018-12-02 17:28:11
Par : Clement
*/


/*
	Cette librairie appelle le fichier .sh qui lance gnuplot avec les bons parametres.
*/
  
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
