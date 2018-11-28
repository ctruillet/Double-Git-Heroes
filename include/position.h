/*
 * librairie position.h
 */

//typedef struct Coordonnees;

typedef struct{
	float t;
	float x;
	float y;
	float z;
} Coordonnees;
//à bouger?

void new_coord(Coordonnees *point, float dt);