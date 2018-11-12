#include <stdio.h>
#include "position.h"


void new_coord(Coordonnees *point, float dt){
	//Sauvegarde des anciennes coordonées
	float x=point->x;
	float y=point->y;
	float z=point->z;

	//Calcul des nouvelles coordonées	
	point->x = S*(y-x);
	point->y = x*(P-z)-y;
	point->z = x*y - B*z;
	point->t += dt;
}