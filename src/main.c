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
	const char DATA[128] = "../data/position.dat"	;	//Nom du fichier contenant les positions
	int mode;

	float Tmax = 500; 	//Valeur min = 0, Valeur max = 40
	float dt = 0.01;	//Valeur min = 0.005 , Valeur max = 5

	float B = 8/3;		//Valeur par défaut : 8/3
	float P = 28;		//Valeur par défaut : 28
	float S = 10;		//Valeur par défaut : 10
	
	Coord point = new_coord(0, 1, 2, 3); //Ceci doit bouger

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
	
	choix_mode(&mode,LOG); //Choix du mode;

	w_log(LOG,"Fin de la phase d'Initialisation.");
	
	
	/*Calculs
	*	Calcul des nouvelles positions
	*	Stockage dans lorentz.dat
	*/
	
	
	w_log(LOG,"Début de la phase de Calcul.");

	
	FILE* fichier = NULL;

	fichier = fopen(DATA,"a"); //Ouverture en mode ajout

	if (fichier != NULL){ // On peut lire et écrire dans le fichier
	
		w_fichier(fichier, point); //On ecrit la position à t = 0
		
		while (get_t(point) <= Tmax){
			switch(mode){
				case 0: //Lorenz
					point = position_next_Lorenz(point, dt, B, P, S);
					break;
				case 1:  //Van Der Pol
					point = position_next_VanDerPol(point, dt, 0.02, 4, 0.2, 0.2, 10, 0.1);
					break;
				case 2: // Rössler
					point = position_next_Rossler(point, dt, 0.2, 0.2, 5.7);
					break;
				default:
					w_log(LOG,"[ERROR] Pas d\'attracteur selectionné.");

			}	
			w_fichier(fichier, point);
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
	
	
	trace_courbe(mode,DATA,LOG);
	w_log(LOG,"FIN.");
	
	
	return(0);
}