/*
 * librairie fichier.h
 */

#ifndef __POSITION_H__
	#include "position.h"
#endif
	
//Vider le fichier si il existe déjà, sinon, le vider	
 void init_fichier(const char * FICHIER, char * LOG);
 
 // //Ecrire dans le fichier DATA
 // int w_fichier(FILE* fichier, Coordonnees * point);

 int w_fichier(FILE* fichier, Coord point);