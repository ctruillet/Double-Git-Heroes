#include <stdio.h>

#include "../include/position.h"


typedef struct coordonnees{
	float t;
	float x;
	float y;
	float z;
} Coordonnees;

float get_x(Coor point){
	float x=point->x;
	return(x);
}

float get_y(Coor point){
	float y=point->y;
	return(y);
}

float get_z(Coor point){
	float z=point->z;
	return(z);
}

float * set_x(Coor point){
	return(point.x);
}

float * set_y(Coor point){
	return(point.y);
}

float * set_z(Coor point){
	return(point.z);
}

void new_coord(Coor point, float dt){
	
	//Sauvegarde des anciennes coordonées
	float x=get_x(point);
	float y=get_y(point);
	float z=get_z(point);
	

	//Calcul des nouvelles coordonées	
	point->x += (S*(y-x)) * dt;
	point->y += (x*(P-z)-y) * dt;
	point->z += (x*y - B * z) * dt;
	point->t += dt;
}