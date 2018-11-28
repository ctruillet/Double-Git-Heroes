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

//Calcul de la nouvelle position
Coord position_next_lorenz(Coord point, float dt, float B, float P, float S);
