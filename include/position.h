/*
 * librairie position.h
 */
#define __POSITION_H__

//Structure de la position pour un temps fixe
typedef struct {
	float t; //temps
	float x; 
	float y;
	float z;
} Coordonnees;


void new_coord(Coordonnees * point, float t, float x, float y, float z);

void position_next(Coordonnees * point, float dt, float B, float P, float S);