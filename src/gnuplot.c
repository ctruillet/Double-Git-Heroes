#include <stdio.h>
#include <stdlib.h>
#include "../include/log.h"
#include "../include/gnuplot.h"

/*
	Cette librairie appelle le fichier lorentz.sh qui lance gnuplot avec les bons parametres.
*/
  
void trace_courbe(char * FICHIER, char * LOG){
	
	w_log(LOG, "Ouverture de Gnuplot.");
	
	system("./lorenz.sh");
}
