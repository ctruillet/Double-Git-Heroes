#include <stdio.h>
#include <stdlib.h>
#include "../include/position.h"
#include "../include/log.h"




//Fonction qui lui associe à la structure Coordonnees les valeurs pour x, y, z et t
void new_coord(Coordonnees * point, float t, float x, float y, float z){
	point->t = t;
	point->x = x;
	point->y = y;
	point->z = z;

}

void position_next(Coordonnees * point, float dt, float B, float P, float S){
	//Sauvegarde des anciennes coordonées
	float x = point->x;
	float y = point->y;
	float z = point->z;

	//Calcul des nouvelles coordonées	
	point->x += (S*(y-x)) * dt;
	point->y += (x*(P-z)-y) * dt;
	point->z += (x*y - B*z) * dt;
	point->t += dt;

}