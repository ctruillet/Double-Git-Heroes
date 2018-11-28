#include <stdio.h>
#include <stdlib.h>
#include "../include/position.h"
#include "../include/log.h"

// TEST

//Structure de la position
typedef struct Coord{
	float t; //temps
	float x; 
	float y;
	float z;
} Coordonnees_s;

float get_x (Coord position){
	return position->x;
}

float get_y (Coord position){
	return position->y;
}

float get_z(Coord position){
	return position->z;
}

float get_t (Coord position){
	return position->t;
}

Coord new_coord(float t, float x, float y, float z){
	Coord position;
	position = (Coord)malloc(sizeof(Coordonnees_s));
	
	position->t = t;
	position->x = x;
	position->y = y;
	position->z = z;
	
	return position;
}

Coord position_next(Coord point, float dt, float B, float P, float S){
	//Calcul des nouvelles coordonnees
	float new_x = get_x(point) + (S * (get_y(point) - get_x(point) ) ) * dt;
	float new_y = get_y(point) + (get_x(point) * (P - get_z(point) ) - get_y(point) ) * dt;
	float new_z = get_z(point) + (get_x(point) * get_y(point) - B * get_z(point)) *dt;
	float new_t = get_t(point) + dt;
	
	//Mise à jour de point
	point = new_coord(new_t, new_x, new_y, new_z);
	
	return point;

}

//FIN TEST



// //Fonction qui lui associe à la structure Coordonnees les valeurs pour x, y, z et t
// void new_coord(Coordonnees * point, float t, float x, float y, float z){
	// point->t = t;
	// point->x = x;
	// point->y = y;
	// point->z = z;

// }

// void position_next(Coordonnees * point, float dt, float B, float P, float S){
	// //Sauvegarde des anciennes coordonées
	// float x = point->x;
	// float y = point->y;
	// float z = point->z;

	// //Calcul des nouvelles coordonées	
	// point->x += (S*(y-x)) * dt;
	// point->y += (x*(P-z)-y) * dt;
	// point->z += (x*y - B*z) * dt;
	// point->t += dt;

// }