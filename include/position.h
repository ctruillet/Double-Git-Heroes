/*
 * librairie position.h
 */

#define __POSITION_H__

#ifndef __ENTREES_H__
	#include entrees.h
#endif

#ifndef __PARAM_H__
	#include "param.h"
#endif

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

//Recupere les parametres stockés
void get_Param_Lorenz(Param param, double *B, double *P, double *S);
void get_Param_VanDerPol(Param param, double *K, double *M, double *B, double *S, double *P, double *Q);
void get_Param_Rossler(Param param, double *A, double *B, double *C);

//Création d'une nouvelle coordonnees
Coord new_coord(double t, double x, double y, double z);

//Calcul de la nouvelle position - Attracteur de Lorenz
Coord position_next_Lorenz(Coord point, Param param, double dt);

//Calcul de la nouvelle position - Attracteur de Van der Pol
Coord position_next_VanDerPol(Coord point, Param param, double dt);

//Calcul de la nouvelle position - Attracteur de Rössler
Coord position_next_Rossler(Coord point, Param param, double dt);

Coord choix_position(int mode, char * LOG);

void choix_Tmax(float * Tmax);