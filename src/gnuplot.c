#include <stdio.h>
#include <stdlib.h>
#include "../include/log.h"
#include "../include/gnuplot.h"

/*
	Cette librairie appelle le fichier lorentz.sh qui lance gnuplot avec les bons parametres.
*/
  
void trace_courbe(char * FICHIER){
	
	w_log(FICHIER, "Ouverture de Gnuplot.");
	
	system("./lorentz.sh");
}
