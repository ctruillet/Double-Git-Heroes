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


int lire_int(float * d);

int lire_float(float * f);

int lire_double(double * lf);

int lire_chaine(char * s);

<<<<<<< HEAD
=======
int chance_d(double * lf, char * c);

//Choix de Tmax
void choix_Tmax(float * Tmax);

//Choix du mode
void choix_mode(int * mode, char * LOG);
>>>>>>> e0f2bb1073746678cdba7d17f6841cf277c06a80
