/*
 * librairie param.h
 */

#define __PARAM_H__

<<<<<<< HEAD
#ifndef __ENTREES_H__
	#include "entrees.h"
#endif

#ifndef __POSITION_H__
	#include "position.h"
#endif

=======
>>>>>>> e0f2bb1073746678cdba7d17f6841cf277c06a80
/*
Derniere modification : 2018-12-05 15:44:53
Par : Clement
*/


//Structure des parametres
typedef struct Param_Lorenz * Param_Lorenz;
typedef struct Param_VanDerPol * Param_VanDerPol;
typedef struct Param_Rossler * Param_Rossler;
typedef union Param * Param;

//Set des parametres
Param setLorenz(Param_Lorenz L, Param P);
Param setVanDerPol(Param_VanDerPol V, Param P);
Param setRossler(Param_Rossler R, Param P);

Param setParamLorenz(Param param, double B, double S, double P);
Param setParamVanDerPol(Param param, double K, double M, double B, double S, double P, double Q);
Param setParamRossler(Param param, double A, double B, double C);

<<<<<<< HEAD
Param choix_param(int mode, char * LOG);

void choix_mode(int * mode, char * LOG);

int chance_d(double * lf, char * c);
=======
//Recupere les parametres stockés
void get_Param_Lorenz(Param param, double *B, double *P, double *S);
void get_Param_VanDerPol(Param param, double *K, double *M, double *B, double *S, double *P, double *Q);
void get_Param_Rossler(Param param, double *A, double *B, double *C);
>>>>>>> e0f2bb1073746678cdba7d17f6841cf277c06a80
