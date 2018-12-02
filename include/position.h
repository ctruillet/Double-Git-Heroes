/*
 * librairie position.h
 */
#define __POSITION_H__

//Debut Test

//Ceci est une structure de position
typedef struct Coord * Coord;

//Structure des parametres
typedef struct Param_Lorenz * Param_Lorenz;
typedef struct Param_VanDerPol * Param_VanDerPol;
typedef struct Param_Rossler * Param_Rossler;
typedef union Param * Param;

//Set des parametres
Param setLorenz(Param_Lorenz L, Param P);
Param setVanDerPol(Param_VanDerPol V, Param P);
Param setRossler(Param_Rossler R, Param P);

Param setParamLorenz(Param param, double B, double S, double P);
Param setParamVanDerPol(Param param, double K, double M, double B, double S, double P, double Q);
Param setParamRossler(Param param, double A, double B, double C);

//Recupere la valeur de x de la position
double get_x (Coord position);

//Recupere la valeur de y de la position
double get_y (Coord position);

//Recupere la valeur de z de la position
double get_z(Coord position);

//Recupere la valeur de t de la position
double get_t (Coord position);


//Création d'une nouvelle coordonnees
Coord new_coord(double t, double x, double y, double z);

//Calcul de la nouvelle position - Attracteur de Lorenz
Coord position_next_Lorenz(Coord point, double dt, double B, double P, double S);

//Calcul de la nouvelle position - Attracteur de Van der Pol
Coord position_next_VanDerPol(Coord point, double dt, double K, double M, double B, double S, double P, double Q);

//Calcul de la nouvelle position - Attracteur de Rössler
Coord position_next_Rossler(Coord point, double dt, double A, double B,double C);