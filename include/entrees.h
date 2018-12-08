/*
 * librairie entrees.h
 */
<<<<<<< HEAD
#define __ENTREES_H__
=======

>>>>>>> clem
#ifndef __POSITION_H__
	#include "position.h"
#endif

/*
<<<<<<< HEAD
Derniere modification : 2018-12-06
Par : Valentin
=======
Derniere modification : 2018-12-02 17:43:27
Par : Clement
>>>>>>> clem
*/

//Vider le buffer
void vide_buffer();

//Choisir un mode + Accueil 
void choix_mode(int * mode,char * LOG);

<<<<<<< HEAD
//Chois de la position
Coord choix_position(int mode, char * LOG);

<<<<<<< HEAD
//Choix de Tmax
void choix_Tmax(float * Tmax);

//Choix de dt
void choix_dt(float * dt);

// Choix des parametres
Param choix_param(int mode, char * LOG);



=======
>>>>>>> 6be7515eb6e0d481e798299b9c29b1467c87d61b
int lire_int(float * d);

int lire_float(float * f);

int lire_double(double * lf);

int lire_chaine(char * s);

<<<<<<< HEAD
=======
int chance_d(double * lf, char * c);


<<<<<<< HEAD
=======
//Choix du mode
void choix_mode(int * mode, char * LOG);
>>>>>>> e0f2bb1073746678cdba7d17f6841cf277c06a80
>>>>>>> 6be7515eb6e0d481e798299b9c29b1467c87d61b
=======
//Choix de la position initiale
Coord choix_position(int mode, char * LOG);

// Choix des parametres
Param choix_param(int mode, char * LOG);

//Choix de dt
void choix_dt(float * dt);

//Choix de Tmax
void choix_Tmax(float * Tmax);
>>>>>>> clem
