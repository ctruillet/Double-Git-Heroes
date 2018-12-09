#include <stdio.h>
#include <stdlib.h>
#include "../include/position.h"
#include "../include/log.h"
#include "../include/param.h"
#include "../include/entrees.h"

/*
Derniere modification : 2018-12-02 17:28:26
Par : Clement
*/

//Structure de la position
typedef struct Coord{
	double t; //temps
	double x; 
	double y;
	double z;
} Coordonnees_s;


//Création d'une nouvelle coordonnees
Coord new_coord(double t, double x, double y, double z){
	Coord position;
	position = (Coord)malloc(sizeof(Coordonnees_s));
	
	position->t = t;
	position->x = x;
	position->y = y;
	position->z = z;
	
	return position;
}



//Recupere la valeur de x de la position
double get_x (Coord position){
	return position->x;
}

//Recupere la valeur de y de la position
double get_y (Coord position){
	return position->y;
}

//Recupere la valeur de z de la position
double get_z(Coord position){
	return position->z;
}

//Recupere la valeur de temps de la position
double get_t (Coord position){
	return position->t;
}

//Calcul de la nouvelle position - Attracteur de Lorenz
Coord position_next_Lorenz(Coord point, Param param, double dt){
	double B,P,S;
	get_Param_Lorenz(param, &B, &P, &S); //On assigne la bonne valeur

	//Calcul des nouvelles coordonnees
	double new_x = get_x(point) + (S * (get_y(point) - get_x(point) ) ) * dt;
	double new_y = get_y(point) + (get_x(point) * (P - get_z(point) ) - get_y(point) ) * dt;
	double new_z = get_z(point) + (get_x(point) * get_y(point) - B * get_z(point)) * dt;
	double new_t = get_t(point) + dt;
	
	//Mise à jour de point
	point = new_coord(new_t, new_x, new_y, new_z);
	
	return point;
}

//Calcul de la nouvelle position - Attracteur de Van Der Pol
Coord position_next_VanDerPol(Coord point, Param param, double dt){
	double K, M, B, S, P, Q;
	get_Param_VanDerPol(param, &K, &M, &B, &S, &P, &Q); //On assigne la bonne valeur

	//Calcul des nouvelles coordonnees
	double new_x = get_x(point) + (K * (get_y(point) + M * get_x(point)*(B-get_y(point)*get_y(point) ) ) ) * dt;
	double new_y = get_y(point) + (-get_x(point) + S * get_z(point) ) * dt;
	double new_z = get_z(point) + ( P * get_x(point) - Q * get_y(point))  * dt;
	double new_t = get_t(point) + dt;
	
	//Mise à jour de point
	point = new_coord(new_t, new_x, new_y, new_z);
	
	return point;
}

//Calcul de la nouvelle position - Attracteur de Rössler
Coord position_next_Rossler(Coord point, Param param, double dt){
	double A, B, C;
	get_Param_Rossler(param, &A, &B, &C); //On assigne la bonne valeur

	//Calcul des nouvelles coordonnees
	double new_x = get_x(point) - ((get_y(point) + get_z(point))) * dt;
	double new_y = get_y(point) + (get_x(point) + A * get_y(point) ) * dt;
	double new_z = get_z(point) + ( B + get_x(point) * get_z(point) - C * get_z(point))  * dt;
	double new_t = get_t(point) + dt;
	
	//Mise à jour de point
	point = new_coord(new_t, new_x, new_y, new_z);
	
	return point;
}

//Choix de la position
Coord choix_position(int mode, char * LOG){
    double x,y,z;
    int defaut = 1;
    int marque=0;

    // On demande d'abord si on veut les valeurs par défaut ou non
    printf("\n\nIl est maintenant temps de selectionner la position initiale.\n");
    printf("\t 0. Je suis un(e) aventurier(e) et je veux explorer mon attracteur ! (choix de la position initiale)\n");
    printf("\t 1. J'aime rester dans les sentiers battus (position initiale par défaut)\n");
    lire_int(&defaut);

    switch(defaut){
        case 0: // Cas choix de la position
            w_log(LOG, "Choix de la position initiale."); //Ecriture dans le log

            printf("\nEntrez la position initiale\n");
            if (chance_d(&x, "x?\n")==0){
						if (chance_d(&y, "y?\n")==0){
							if (chance_d(&z, "z?\n")==0){
								marque = 1;
							}
						}
					}
					if(marque==0){
						w_log(LOG, "reponse <position> invalide");
						w_log(LOG, "Position nulle choisie");
                        x = 0;
                        y = 0;
                        z = 0;
                        printf("\n\t-> Position initiale : x=0 y=0 z=0\n");
						
					}
            printf("\n\t-> Position initiale : x=%.2f y=%.2f z=%.2f\n",x,y,z);

            vide_buffer(); //on vide le buffer

        break;

        case 1: //Cas valeur par défaut
            w_log(LOG, "Position initiale par défaut.");

            switch(mode){
                case 0: //Lorenz
                    x = 1;
                    y = 2;
                    z = 3;
                    printf("\n\t-> Position initiale : x=1 y=2 z=3\n");
                    break;

                case 1: //Van Der Pol
                    x = 0.2;
                    y = 0.2;
                    z = 0.2;
                    printf("\n\t-> Position initiale : x=0.1 y=0.1 z=0.1\n");
                    break;

                case 2: //Rossler
                    x = 0;
                    y = 0;
                    z = 0;
                    printf("\n\t-> Position initiale : x=0 y=0 z=0\n");
                    break;
            }

            break;

        default:
            w_log(LOG, "Position nulle choisie");
            x = 0;
            y = 0;
            z = 0;
            printf("\n\t-> Position initiale : x=0 y=0 z=0\n");
            break;
    }

    //on renvoie la structure Coord remplie avec les parametres choisit
    return new_coord(0, x, y, z);
}