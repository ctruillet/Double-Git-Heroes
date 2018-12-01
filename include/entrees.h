/*
 * librairie entrees.h
 */

#ifndef __POSITION_H__
	#include "position.h"
#endif


//Vider le buffer
void vide_buffer();

//Choisir un mode + Accueil 
void choix_mode(int * mode,char * LOG);

Coord choix_position(int mode, char * LOG);

void choix_param(int mode, char * LOG);


/*TODO
    * init param (niveau Satan ++)
    * init dt (easy)
    * fonctions getParam (renvoie la structure des parametres de Lorenz, ou Van Der Pol, ou Rossler)
    * Idem en set
*/