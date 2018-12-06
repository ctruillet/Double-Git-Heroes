#include <stdio.h>
#include <stdlib.h>
#include "../include/position.h"
#include "../include/log.h"
#include "../include/param.h"
#include "../include/entrees.h"

#define TMAX 5000
#define TMIN 10


/*
Derniere modification : 2018-12-06 
Par : valentin
*/

//positions par defaut

Coor defpos_Lorenz = new_coord(10, 1, 2, 3);
Coor defpos_VanDerPol=new_coord(10, 0.2, 0.2, 0.2);
Coor defpos_Rossler=new_coord(10, 0, 0, 0);

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

Coord choix_position(int mode, char * LOG){
    double x,y,z;
    int defaut = 1;
	int ch;

    // On demande d'abord si on veut les valeurs par défaut ou non
    printf("\n\nIl est maintenant temps de selectionner la position initiale.\n");
    printf("\t 0. Je suis un(e) aventurier(e) et je veux explorer mon attracteur ! (choix de la position initiale)\n");
    printf("\t 1. J'aime rester dans les sentiers battus (position initiale par défaut)\n");
    lire_int(&defaut);


    switch(defaut){
        case 0: // Cas choix de la position
            w_log(LOG, "Choix de la position initiale."); //Ecriture dans le log

            printf("\nEntrez la position initiale\n");
			printf("x?\n");
			while(lire_double(&x)==1 && ch<CHANCES){
				ch++;
				printf("x?\n");
			}
			if(ch<CHANCES){
				printf("y?\n");
			}
			while(lire_double(&y)==1 && ch<CHANCES){
				ch++;
				printf("y?\n");
			}
			if(ch<CHANCES){
				printf("z?\n");
			}
			while(lire_double(&z)==1 && ch<CHANCES){
				ch++;
				printf("z?\n");
			}
			if (ch>=CHANCES){
				w_log(LOG, "trops d'erreurs <choix de position>");
				w_log(LOG, "Position nulle choisie");
				x = 0;
				y = 0;
				z = 0;
			}
            printf("\n\t-> Position initiale : x=%.2lf y=%.2lf z=%.2lf\n",x,y,z);

        break;

        case 1: //Cas valeur par défaut
            w_log(LOG, "Position initiale par défaut.");

            switch(mode){
                case 0: //Lorenz
                    x = get_x(defpos_Lorenz);
                    y = get_y(defpos_Lorenz);
                    z = get_z(defpos_Lorenz);
                    printf("\n\t-> Position initiale : x=%lf y=%lf z=%lf\n",x,y,z);
                    break;

                case 1: //Van Der Pol
                    x = get_x(defpos_VanDerPol);
                    y = get_y(defpos_VanDerPol);
                    z = get_z(defpos_VanDerPol);
                    printf("\n\t-> Position initiale : x=%lf y=%lf z=%lf\n",x,y,z);
                    break;

                case 2: //Rossler
                    x = get_x(defpos_Rossler);
                    y = get_y(defpos_Rossler);
                    z = get_z(defpos_Rossler);
                    printf("\n\t-> Position initiale : x=%lf y=%lf z=%lf\n",x,y,z);
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
    return new_coord(0, x, y, z);;
}

void choix_Tmax(float * Tmax){
	int ch = 0;
    printf("\nNonobstant l'envie de dessiner un attracteur jusqu'à un temps infini, il vous est demandé de fournir un temps d'arrêt.");
    printf("\n\tBien évidemment, nous veillerons a ne pas recevoir un temps trop grand ou nul.");
    printf("\n\tC'est pour celà qu'est fixée une valeur minimum et maximum Tmin = 10s et Tmax = 5000s.\n");
    while(lire_float(Tmax)==1 && ch<CHANCES){
		ch++;
		printf("T?\n");
	}
    
    if ((*Tmax) < TMIN){
        (*Tmax) = TMIN;
    }else{
        if ((*Tmax) > TMAX){
            (*Tmax) = TMAX;
        }
    }
    printf("\n\t-> Tmax = %.2f s",(*Tmax));
}