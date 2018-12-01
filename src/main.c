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

	Param parameters; //Parametres

	float Tmax;
	float dt;	

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

	Coord point = choix_position(mode, LOG); //Entrée de la position initiale

	choix_dt(&dt); //Choix de dt

	choix_Tmax(&Tmax); //Choix de Tmax

	parameters = choix_param(mode, LOG);//Entrée des parametres

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
					point = position_next_Lorenz(point, dt, 8/3, 28, 10);
					break;
				case 1:  //Van Der Pol
					point = position_next_VanDerPol(point, dt, 0.02, 4, 0.2, 0.2, 10, 0.1);
					break;
				case 2: // Rössler
					point = position_next_Rossler(point, dt, 0.2, 0.2, 14);
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
		exit(-1); //Eviter de lancer gnuplot
    }
	
	
	w_log(LOG,"Fin de la phase de Calcul.");
	
	
	/*Affichage
	*	Appel de trace_courbe (librairie Gnuplot)
	*/
	
	printf("\n\t Calcul de %.0f positions ...\n",Tmax/dt);
	trace_courbe(mode,DATA,LOG);

	w_log(LOG,"FIN.");
	

	return(0);
}