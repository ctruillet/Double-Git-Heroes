/*
 * librairie entrees.h
 */
#define __ENTREES_H__
#ifndef __POSITION_H__
	#include "position.h"
#endif

/*
Derniere modification : 2018-12-09 10:56:09
Par : Valentin
*/

//Vider le buffer
void vide_buffer();

//Choix du mode
void choix_mode(int * mode, char * LOG);

//Choix de Tmax
void choix_Tmax(float * Tmax);

//Choix de dt
void choix_dt(float * dt);

//Choisir un mode + Accueil 
void choix_mode(int * mode,char * LOG);


int lire_int(int * d);

int lire_float(float * f);

int lire_double(double * lf);

int lire_chaine(char * s);

//fonction qui donne des chances à l'utilisateur de resaisir une entrée lors d'une erreur
int chance_d(double * lf, char * c);





