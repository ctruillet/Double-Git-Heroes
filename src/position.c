#include <stdio.h>
#include <stdlib.h>
#include "../include/position.h"
#include "../include/log.h"
#include "../include/param.h"

/*
Derniere modification : 2018-12-02 17:28:26
Par : Clement
*/

//Structure de la position
typedef struct Coord{
	double t; //temps
	double x; 
	double y;
	double z;
} Coordonnees_s;


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