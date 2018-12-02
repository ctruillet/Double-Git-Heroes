#ifndef__POSITION_H__
	#include "../include/position.h
	#def__POSITION_H__
#endif

 void init_position(Coordonnees *point, float *Tmax);
 
 void init_parametres(float *S, float *B, float *P);
 
 void maj_vitesse(float *dt);
 
 void viderBuffer();
 
 int lire(char *chaine, int longueur);
 
 int verifFloat(char * c);
 
float char_to_float(char * c);

int lire_float(float * f);
