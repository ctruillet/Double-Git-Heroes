/*
 * librairie position.h
 */

typedef struct{
	float t;
	float x;
	float y;
	float z;
} Coordonnees;

void new_coord(Coordonnees *point, float dt){