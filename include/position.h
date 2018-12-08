/*
 * librairie position.h
 */
#define __POSITION_H__

<<<<<<< HEAD
<<<<<<< HEAD
#ifndef __ENTREES_H__
	#include "entrees.h"
#endif

=======
>>>>>>> e0f2bb1073746678cdba7d17f6841cf277c06a80
#ifndef __PARAM_H__
	#include "param.h"
#endif
	

=======
#ifndef __PARAM_H__
	#include "param.h"
#endif
	

>>>>>>> clem
/*
Derniere modification : 2018-12-02 17:43:52
Par : Clement
*/


//Ceci est une structure de position
typedef struct Coord * Coord;

//Recupere la valeur de x de la position
double get_x (Coord position);

//Recupere la valeur de y de la position
double get_y (Coord position);

//Recupere la valeur de z de la position
double get_z(Coord position);

//Recupere la valeur de t de la position
double get_t (Coord position);

//Création d'une nouvelle coordonnees
Coord new_coord(double t, double x, double y, double z);

//Calcul de la nouvelle position - Attracteur de Lorenz
Coord position_next_Lorenz(Coord point, Param param, double dt);

//Calcul de la nouvelle position - Attracteur de Van der Pol
Coord position_next_VanDerPol(Coord point, Param param, double dt);

//Calcul de la nouvelle position - Attracteur de Rössler
<<<<<<< HEAD
<<<<<<< HEAD
Coord position_next_Rossler(Coord point, Param param, double dt);

//definie la position initiale
Coord choix_position(int mode, char * LOG);

//definie le temps d'observation de la trajectoire
void choix_Tmax(float * Tmax);
=======
Coord position_next_Rossler(Coord point, Param param, double dt);
>>>>>>> e0f2bb1073746678cdba7d17f6841cf277c06a80
=======
Coord position_next_Rossler(Coord point, Param param, double dt);
>>>>>>> clem
