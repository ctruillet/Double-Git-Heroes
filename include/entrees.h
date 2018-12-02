/*
 * librairie entrees.h
 */

#ifndef __POSITION_H__
	#include "position.h"
#endif

/*
Derniere modification : 2018-12-02 17:43:27
Par : Clement
*/

//Vider le buffer
void vide_buffer();

//Choisir un mode + Accueil 
void choix_mode(int * mode,char * LOG);

//Choix de la position initiale
Coord choix_position(int mode, char * LOG);

// Choix des parametres
Param choix_param(int mode, char * LOG);

//Choix de dt
void choix_dt(float * dt);

//Choix de Tmax
void choix_Tmax(float * Tmax);