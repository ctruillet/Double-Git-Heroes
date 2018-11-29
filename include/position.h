/*
 * librairie position.h
 */
#define __POSITION_H__

//Debut Test

//Ceci est une structure de position
typedef struct Coord * Coord;

//Recupere la valeur de x de la position
float get_x (Coord position);

//Recupere la valeur de y de la position
float get_y (Coord position);

//Recupere la valeur de z de la position
float get_z(Coord position);

//Recupere la valeur de t de la position
float get_t (Coord position);


//Création d'une nouvelle coordonnees
Coord new_coord(float t, float x, float y, float z);

//Calcul de la nouvelle position - Attracteur de Lorenz
Coord position_next_Lorenz(Coord point, float dt, float B, float P, float S);

//Calcul de la nouvelle position - Attracteur de Van der Pol
Coord position_next_VanDerPol(Coord point, float dt, float k, float m, float b, float s, float p, float q);

//Calcul de la nouvelle position - Attracteur de Rössler
Coord position_next_Rossler(Coord point, float dt, float a, float b, float c);