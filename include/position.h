/*
 * librairie position.h
 */
#define __POSITION_H__

//Debut Test

//Ceci est une structure de position
typedef struct Coord * Coord;

float get_x (Coord position);

float get_y (Coord position);

float get_z(Coord position);

float get_t (Coord position);

Coord new_coord(float t, float x, float y, float z);

Coord position_next(Coord point, float dt, float B, float P, float S);


//Fin Test




// //Structure de la position pour un temps fixe
// typedef struct {
	// float t; //temps
	// float x; 
	// float y;
	// float z;
// } Coordonnees;


// void new_coord(Coordonnees * point, float t, float x, float y, float z);

// void position_next(Coordonnees * point, float dt, float B, float P, float S);