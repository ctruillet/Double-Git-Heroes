#include <stdio.h>
#include <stdlib.h>
#include "../include/param.h"
#include "../include/log.h"

/*
Derniere modification : 2018-12-05 15:42:43
Par : Clement
*/

// Structures des parametres

typedef struct Param_Lorenz{
	double B;
	double P;
	double S;
}Param_Lorenz_s;

typedef struct Param_VanDerPol{
	double K;
	double M;
	double B;
	double S;
	double P;
	double Q;
}Param_VanDerPol_s;

typedef struct Param_Rossler{
	double A;
	double B;
	double C;
}Param_Rossler_s;

//Parametres
typedef union Param{
	Param_Lorenz lorenz;
	Param_VanDerPol vanderpol;
	Param_Rossler rossler;
}Param_s;


//Fonctions assignant les parametres du mode choisis dans l'union
Param setLorenz(Param_Lorenz L, Param P){
	P = (Param)malloc(sizeof(Param_s));
	P->lorenz = (Param_Lorenz)L;
	return P;
}

Param setVanDerPol(Param_VanDerPol V, Param P){
	P = (Param)malloc(sizeof(Param_s));
	P->vanderpol = (Param_VanDerPol)V;
		
	return P;
}
 
Param setRossler(Param_Rossler R, Param P){
	P = (Param)malloc(sizeof(Param_s));
	P->rossler = (Param_Rossler)R;
		
	return P;
}

//Recupere les parametres stockés - Lorenz
void get_Param_Lorenz(Param param, double *B, double *P, double *S){
	(*B) = param->lorenz->B;
	(*P) = param->lorenz->P;
	(*S) = param->lorenz->S;
}

//Recupere les parametres stockés - Van Der Pol
void get_Param_VanDerPol(Param param, double *K, double *M, double *B, double *S, double *P, double *Q){
	(*K) = param->vanderpol->K;
	(*M) = param->vanderpol->M;
	(*B) = param->vanderpol->B;
	(*S) = param->vanderpol->S;
	(*P) = param->vanderpol->P;
	(*Q) = param->vanderpol->Q;
}

//Recupere les parametres stockés - Rossler
void get_Param_Rossler(Param param, double *A, double *B, double *C){
	(*A) = param->rossler->A;
	(*B) = param->rossler->B;
	(*C) = param->rossler->C;
}

//remplissage des parametres
Param setParamLorenz(Param param, double B, double P, double S){
	Param_Lorenz parametersL;
	parametersL = (Param_Lorenz)malloc(sizeof(Param_Lorenz_s));
	
	parametersL->B = B;
	parametersL->P = P;
	parametersL->S = S;

	return setLorenz(parametersL,param);
}

Param setParamVanDerPol(Param param, double K, double M, double B, double S, double P, double Q){

	Param_VanDerPol parametersV;
	parametersV = (Param_VanDerPol)malloc(sizeof(Param_VanDerPol_s));

	parametersV->K = K;
	parametersV->M = M;
	parametersV->B = B;
	parametersV->S = S;
	parametersV->P = P;
	parametersV->Q = Q;

	return setVanDerPol(parametersV,param);

}

Param setParamRossler(Param param, double A, double B, double C){
	Param_Rossler parametersR;
	parametersR = (Param_Rossler)malloc(sizeof(Param_Rossler_s));

	parametersR->A = A;
	parametersR->B = B;
	parametersR->C = C;

	return setRossler(parametersR,param);

}