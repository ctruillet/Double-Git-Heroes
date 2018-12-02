#include <stdio.h>
#include <stdlib.h>
#include "../include/position.h"
#include "../include/log.h"

/*
Derniere modification : 2018-12-02 23:09:06
Par : Clement
*/

//Structure de la position
typedef struct Coord{
	double t; //temps
	double x; 
	double y;
	double z;
} Coordonnees_s;

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
//Permet de stocker les parametres dans une seule structure (union)
typedef union Param{
	Param_Lorenz lorenz;
	Param_VanDerPol vanderpol;
	Param_Rossler rossler;
}Param_s;



//Création d'une nouvelle coordonnees
Coord new_coord(double t, double x, double y, double z){
	Coord position;
	position = (Coord)malloc(sizeof(Coordonnees_s));
	
	position->t = t;
	position->x = x;
	position->y = y;
	position->z = z;
	
	return position;
}

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


//Remplissage des parametres
Param setParamLorenz(Param param, double B, double P, double S){
	Param_Lorenz parametersL;
	parametersL = (Param_Lorenz)malloc(sizeof(Param_Lorenz_s)); //On assigne la memoire
	
	//On remplit
	parametersL->B = B; 
	parametersL->P = P;
	parametersL->S = S;

	return setLorenz(parametersL,param);
}

Param setParamVanDerPol(Param param, double K, double M, double B, double S, double P, double Q){

	Param_VanDerPol parametersV;
	parametersV = (Param_VanDerPol)malloc(sizeof(Param_VanDerPol_s)); //On assigne la memoire

	//On remplit
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
	parametersR = (Param_Rossler)malloc(sizeof(Param_Rossler_s)); //On assigne la memoire

	//On remplit
	parametersR->A = A;
	parametersR->B = B;
	parametersR->C = C;

	return setRossler(parametersR,param);
}



//Recupere la valeur de x de la position
double get_x (Coord position){
	return position->x;
}

//Recupere la valeur de y de la position
double get_y (Coord position){
	return position->y;
}

//Recupere la valeur de z de la position
double get_z(Coord position){
	return position->z;
}

//Recupere la valeur de temps de la position
double get_t (Coord position){
	return position->t;
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



//Calcul de la nouvelle position - Attracteur de Lorenz
Coord position_next_Lorenz(Coord point, Param param, double dt){
	double B,P,S;
	get_Param_Lorenz(param, &B, &P, &S); //On assigne la bonne valeur

	//Calcul des nouvelles coordonnees
	double new_x = get_x(point) + (S * (get_y(point) - get_x(point) ) ) * dt;
	double new_y = get_y(point) + (get_x(point) * (P - get_z(point) ) - get_y(point) ) * dt;
	double new_z = get_z(point) + (get_x(point) * get_y(point) - B * get_z(point)) * dt;
	double new_t = get_t(point) + dt;
	
	//Mise à jour de point
	point = new_coord(new_t, new_x, new_y, new_z);
	
	return point;

}

//Calcul de la nouvelle position - Attracteur de Van Der Pol
Coord position_next_VanDerPol(Coord point, Param param, double dt){
	double K, M, B, S, P, Q;
	get_Param_VanDerPol(param, &K, &M, &B, &S, &P, &Q); //On assigne la bonne valeur

	//Calcul des nouvelles coordonnees
	double new_x = get_x(point) + (K * (get_y(point) + M * get_x(point)*(B-get_y(point)*get_y(point) ) ) ) * dt;
	double new_y = get_y(point) + (-get_x(point) + S * get_z(point) ) * dt;
	double new_z = get_z(point) + ( P * get_x(point) - Q * get_y(point))  * dt;
	double new_t = get_t(point) + dt;
	
	//Mise à jour de point
	point = new_coord(new_t, new_x, new_y, new_z);
	
	return point;
}

//Calcul de la nouvelle position - Attracteur de Rössler
Coord position_next_Rossler(Coord point, Param param, double dt){
	double A, B, C;
	get_Param_Rossler(param, &A, &B, &C); //On assigne la bonne valeur

	//Calcul des nouvelles coordonnees
	double new_x = get_x(point) - ((get_y(point) + get_z(point))) * dt;
	double new_y = get_y(point) + (get_x(point) + A * get_y(point) ) * dt;
	double new_z = get_z(point) + ( B + get_x(point) * get_z(point) - C * get_z(point))  * dt;
	double new_t = get_t(point) + dt;
	
	//Mise à jour de point
	point = new_coord(new_t, new_x, new_y, new_z);
	
	return point;
}