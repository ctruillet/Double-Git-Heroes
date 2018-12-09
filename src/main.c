#include <stdio.h>
#include <stdlib.h>
#include "../include/param.h"
#include "../include/position.h"
#include "../include/entrees.h"
#include "../include/fichier.h"
#include "../include/gnuplot.h"
#include "../include/log.h"

/*
Derniere modification : 2018-12-02 17:28:35
Par : Clement
*/

int main(int argc, char *argv[]){
	//Déclaration des variables
	char LOG[128]; 										//Nom du fichier .log 
	const char DATA[128] = "../data/position.dat"	;	//Nom du fichier contenant les positions
	int mode;											//Permet de voir quel systeme dynamique est selectionné

	Param parameters; //Parametres

	float Tmax; 	//Variable de Temps d'arrêt de calcul
	float dt;		//Variable d'increment de temps

	/*Initialisation
	* 	Création du fichier .log
	*	Initialisation du fichier lorentz.dat (situé dans ./data/)
	*	
	*	Entrées
	*		Systéme dynamique
	*		Position initiale
	* 		Tmax
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

	w_log(LOG,"Fin de la phase d'Initialisation."); //Fin de phase -> ecriture dans log
	
	
	/*Calculs
	*	Ouverture du fichier position.dat
	*	Calcul des nouvelles positions
	*	Stockage dans position.dat
	*	Fermeture du fichier position.dat
	*/
	
	
	w_log(LOG,"Début de la phase de Calcul."); 				//Début de phase -> ecriture dans log
	printf("\n\t Calcul de %.0f positions ...\n",Tmax/dt);	//Affichage de nombre de positions a calculer, inutile donc indispensable
	
	FILE* fichier = NULL;

	fichier = fopen(DATA,"a"); //Ouverture en mode ajout

	if (fichier != NULL){ // On peut lire et écrire dans le fichier
	
		w_fichier(fichier, point); //On ecrit la position à t = 0
		
		while (get_t(point) <= Tmax){
			switch(mode){
				case 0: //Lorenz
					point = position_next_Lorenz(point, parameters, dt);
					break;
				case 1:  //Van Der Pol
					point = position_next_VanDerPol(point, parameters, dt);
					break;
				case 2: // Rössler
					point = position_next_Rossler(point, parameters, dt);
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
	
	
	w_log(LOG,"Fin de la phase de Calcul.");	//Fin de phase -> ecriture dans log
	
	
	/*Affichage
	*	Appel de trace_courbe (librairie Gnuplot)
	*/
	
	trace_courbe(mode,LOG);

	w_log(LOG,"FIN."); //Fin de phase -> ecriture dans log
	

	return(0);
}