/*
 * librairie fichier.h
 */

#ifndef __POSITION_H__
	#include "position.h"
#endif
	
 void init_fichier(const char * FICHIER, char * LOG);
 
 int w_fichier(const char * FICHIER, Coordonnees * point);
 
 int w_fichier_test(FILE* fichier, Coordonnees * point);
