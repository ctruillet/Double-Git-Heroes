/*
 * librairie entrees.h
 */
#define __ENTREES_H__
#ifndef __POSITION_H__
	#include "position.h"
#endif

/*
Derniere modification : 2018-12-06
Par : Valentin
*/

//Vider le buffer
void vide_buffer();

//Choisir un mode + Accueil 
void choix_mode(int * mode,char * LOG);

//Choix de la position
Coord choix_position(int mode, char * LOG);

//Choix des parametres
Param choix_param(int mode, char * LOG);

//Choix Tmax
void choix_Tmax(float * Tmax);

//Choix dt
void choix_dt(float * dt);

int lire_int(float * d);

int lire_float(float * f);

int lire_double(double * lf);

int lire_chaine(char * s);

int chance_d(double * lf, char * c);

