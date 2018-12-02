#include <stdio.h>

#include "../include/position.h"


typedef struct coordonnees{
	float t;
	float x;
	float y;
	float z;
} Coordonnees;

void new_coord(Coordonnees * point, float dt){
	//Sauvegarde des anciennes coordonées
	float x=point->x;
	float y=point->y;
	float z=point->z;

	//Calcul des nouvelles coordonées	
	point->x += (S*(y-x)) * dt;
	point->y += (x*(P-z)-y) * dt;
	point->z += (x*y - B * z) * dt;
	point->t += dt;
}
(int*)(sksk)