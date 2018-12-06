/*
 * librairie param.h
 */

#define __PARAM_H__

#ifndef __ENTREES_H__
	#include "entrees.h"
#endif

#ifndef __POSITION_H__
	#include "position.h"
#endif

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

void choix_dt(float * dt);

Param setParamLorenz(Param param, double B, double S, double P);
Param setParamVanDerPol(Param param, double K, double M, double B, double S, double P, double Q);
Param setParamRossler(Param param, double A, double B, double C);

Param choix_param(int mode, char * LOG);

void choix_mode(int * mode, char * LOG);

int chance_d(double * lf, char * c);