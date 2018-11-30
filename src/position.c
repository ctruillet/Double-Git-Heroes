#include <stdio.h>
#include <stdlib.h>
#include "../include/position.h"
#include "../include/log.h"

//Structure de la position
typedef struct Coord{
	float t; //temps
	float x; 
	float y;
	float z;
} Coordonnees_s;

// Structures des parametres

typedef struct Param_Lorenz{
	float B;
	float P;
	float S;
}Param_Lorenz_s;

typedef struct Param_VanDerPol{
	float k;
	float m;
	float b;
	float s;
	float p;
	float q;
}Param_VanDerPol_s;

typedef struct Param_Rossler{
	float a;
	float b;
	float c;
}Param_Rossler_s;

//Parametres
typedef union Param{
	Param_Lorenz lorenz;
	Param_VanDerPol vanderpol;
	Param_Rossler rossler;
}Param_s;


//Fonctions assignant les parametres du mode choisis dans l'union
void setLorenz(Param_Lorenz L, Param P){
	P->lorenz = (Param_Lorenz)&L;
}

void setVanDerPol(Param_VanDerPol V, Param P){
	P->vanderpol = (Param_VanDerPol)&V;
}

void setRossler(Param_Rossler R, Param P){
	P->rossler = (Param_Rossler)&R;
}

//remplissage des parametres
Param_Lorenz setParamLorenz(float B, float S, float P){
	Param_Lorenz parameters;
	parameters = (Param_Lorenz)malloc(sizeof(Param_Lorenz_s));

	parameters->B = B;
	parameters->P = P;
	parameters->S = S;

	return parameters;
}

Param_VanDerPol setParamVanDerPol(float k, float m, float b, float s, float p, float q){
	Param_VanDerPol parameters;
	parameters = (Param_VanDerPol)malloc(sizeof(Param_VanDerPol_s));

	parameters->k = k;
	parameters->m = m;
	parameters->b = b;
	parameters->s = s;
	parameters->p = p;
	parameters->q = q;

	return parameters;
}

Param_Rossler setParamRossler(float a, float b, float c){
	Param_Rossler parameters;
	parameters = (Param_Rossler)malloc(sizeof(Param_Rossler_s));

	parameters->a = a;
	parameters->b = b;
	parameters->c = c;

	return parameters;
}



//Recupere la valeur de x de la position
float get_x (Coord position){
	return position->x;
}

//Recupere la valeur de y de la position
float get_y (Coord position){
	return position->y;
}

//Recupere la valeur de z de la position
float get_z(Coord position){
	return position->z;
}

//Recupere la valeur de temps de la position
float get_t (Coord position){
	return position->t;
}

//Création d'une nouvelle coordonnees
Coord new_coord(float t, float x, float y, float z){
	Coord position;
	position = (Coord)malloc(sizeof(Coordonnees_s));
	
	position->t = t;
	position->x = x;
	position->y = y;
	position->z = z;
	
	return position;
}

//Calcul de la nouvelle position - Attracteur de Lorenz
Coord position_next_Lorenz(Coord point, float dt, float B, float P, float S){
	//Calcul des nouvelles coordonnees
	float new_x = get_x(point) + (S * (get_y(point) - get_x(point) ) ) * dt;
	float new_y = get_y(point) + (get_x(point) * (P - get_z(point) ) - get_y(point) ) * dt;
	float new_z = get_z(point) + (get_x(point) * get_y(point) - B * get_z(point)) * dt;
	float new_t = get_t(point) + dt;
	
	//Mise à jour de point
	point = new_coord(new_t, new_x, new_y, new_z);
	
	return point;

}

//Calcul de la nouvelle position - Attracteur de Van Der Pol
Coord position_next_VanDerPol(Coord point, float dt, float k, float m, float b, float s, float p, float q){
	//Calcul des nouvelles coordonnees
	float new_x = get_x(point) + (k * (get_y(point) + m * get_x(point)*(b-get_y(point)*get_y(point) ) ) ) * dt;
	float new_y = get_y(point) + (-get_x(point) + s * get_z(point) ) * dt;
	float new_z = get_z(point) + ( p * get_x(point) - q * get_y(point))  * dt;
	float new_t = get_t(point) + dt;
	
	//Mise à jour de point
	point = new_coord(new_t, new_x, new_y, new_z);
	
	return point;
}

//Calcul de la nouvelle position - Attracteur de Rössler
Coord position_next_Rossler(Coord point, float dt, float a, float b, float c){
	//Calcul des nouvelles coordonnees
	float new_x = get_x(point) - ((get_y(point) + get_z(point))) * dt;
	float new_y = get_y(point) + (get_x(point) + a * get_y(point) ) * dt;
	float new_z = get_z(point) + ( a + get_x(point) * get_z(point) - c * get_z(point))  * dt;
	float new_t = get_t(point) + dt;
	
	//Mise à jour de point
	point = new_coord(new_t, new_x, new_y, new_z);
	
	return point;
}