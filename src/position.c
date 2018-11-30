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