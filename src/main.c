#include <stdio.h>
#include <stdlib.h>
#include "../include/position.h"
#include "../include/entrees.h"
#include "../include/fichier.h"
#include "../include/gnuplot.h"
#include "../include/log.h"



int main(int argc, char *argv[]){
	//Déclaration des variables
	char LOG[128]; 								//Nom du fichier .log 
	const char DATA[128] = "./data/lorentz.dat"	;	//Nom du fichier contenant les positions
	
	float Tmax = 20; 	//Valeur min = 0, Valeur max = 40
	float dt = 0.005;	//Valeur min = 0.005 , Valeur max = 5
	float B = 8/3;		//Valeur par défaut : 8/3
	float P = 28;		//Valeur par défaut : 28
	float S = 10;		//Valeur par défaut : 10
	
	Coordonnees point;  
	new_coord(&point, 0, 1, 2, 3);
	
	
	/*Initialisation
	* 	Création du fichier .log
	*	Initialisation du fichier lorentz.dat (situé dans ./data/)
	*	
	*	Entrées
	*		Position initiale
	*		dt
	*		parametres
	*/
	
	
	crea_log(LOG); 				//Création du fichier log
	init_fichier(DATA,LOG);		//Création du fichier lorentz.dat
	
	w_log(LOG,"Fin de la phase d'Initialisation.");
	
	
	/*Calculs
	*	Calcul des nouvelles positions
	*	Stockage dans lorentz.dat
	*/
	
	
	w_log(LOG,"Début de la phase de Calcul.");

	
	FILE* fichier = NULL;

	fichier = fopen(DATA,"a"); //Ouverture en mode ajout

	if (fichier != NULL){ // On peut lire et écrire dans le fichier
	
		w_fichier(fichier, &point); //On ecrit la position à t = 0
		
		while (point.t <= Tmax){  
			position_next(&point, dt, B, P, S);
			w_fichier(fichier, &point);
		}
		fclose(fichier);
	}
	else{ // On retourne l'erreur à la fonction main qui arrete l'execution
		w_log(LOG,"[ERROR] Impossible d'ouvrir le fichier .dat");
		exit(1);
    }
	
	
	w_log(LOG,"Fin de la phase de Calcul.");
	
	
	/*Affichage
	*	Appel de trace_courbe (librairie Gnuplot)
	*/
	
	
	trace_courbe(DATA,LOG);
	w_log(LOG,"FIN.");
	
	
	return(0);
}