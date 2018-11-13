#include <stdio.h>
#include <stdlib.h>

/*
	Cette librairie appelle le fichier lorentz.sh qui lance gnuplot avec les bons parametres.
*/
  
void trace_courbe(){
	system("./lorentz.sh");
}
