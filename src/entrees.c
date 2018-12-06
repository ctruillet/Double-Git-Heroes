
#include <stdio.h>
#include "../include/entrees.h"
#include "../include/log.h"
#include "../include/position.h"
#include "../include/param.h"

#define CHANCE 2

#define DT_MAX 0.01
#define DT_MIN 0.0005
#define TMAX 5000
#define TMIN 10

/*
Derniere modification : 2018-12-06 
Par : Valentin
*/

int lireFinL(){
	char c=getchar();
	int i=0;
	while(c!='\n'){
		c=getchar();
		i++;
	}
	return(i);
}

void vide_buffer(){
    int c = 0;
    while(c != '\n' && c != EOF){
        c = getchar();
    }
}

int lire_format(const char * c, void * n){
	int lu=scanf(c, n);
	int nb=lireFinL();
	
	if(lu!=1 || nb>0){
		return 1;
	}
	else{
		return 0;
	}
}

int lire_int(float * d){
	const char * c="%d";
	if(lire_format(c, d)==1){
		return 1;
	}
	return 0;
}

int lire_float(float * f){
	const char * c="%f";
	if(lire_format(c, f)==1){
		return 1;
	}
	return 0;
}

int lire_double(double * lf){
	const char * c="%lf";
	if(lire_format(c, lf)==1){
		return 1;
	}
	return 0;
}

int lire_chaine(char * s){
	const char * c="%s";
	if(lire_format(c, s)==1){
		return 1;
	}
	return 0;
}



int chance_d(double * lf, char * c){
	int ch;
	printf("%s",c);
	for(ch=0; lire_double (lf)==0 && ch<CHANCE; ch++){
		printf("%s",c);
	}
	if(ch>=CHANCE){
		return 1;
	}
	return 0;
}


void choix_dt(float * dt){
	int ch=0;
    printf("\nVoici venu le temps de regler l'increment de temps.");
    printf("\n\tAttention, plus l'increment sera petit, plus les calculs seront nombreux.");
    printf("\n\t dt min = 0.0005s et dt max = 0.01s.\n");
    while(lire_float(dt)==1 && ch<CHANCE){
		ch++;
		printf("dt?\n");
	}
    
    if ((*dt) < DT_MIN){
        (*dt) = DT_MIN;
    }else{
        if ((*dt)>DT_MAX){
            (*dt) = DT_MAX;
        }
    }
    printf("\n\t-> dt = %.4f s",(*dt));
}


Param choix_param(int mode, char * LOG){ 
    Param parameters;
    int defaut = 1;
    double B=0, P=0, S=0;
    double K=0, M=0, Q=0;
    double A=0, C=0;
	int marque=0;

    printf("\n\nRentrons un peu plus dans les détails et choisissons les parametres.\n");
    printf("Voulez-vous les parametres par défaut ?");
    printf("\n\t 0. Non ! J'aime choisir mon mode de vie.");
    printf("\n\t 1. Oui ! J'aurais de plus belles courbes.\n");
    scanf("%d",&defaut);

    switch(defaut){
        case 0:
            w_log(LOG, "Choix des parametres."); //Ecriture dans le log
            printf("\n\nEntrez les parametres sous leurs formes décimales");

            switch(mode){
                case 0: //Lorenz
					if (chance_d(&B, "ß?\n")==0){
						if (chance_d(&P, "ρ?\n")==0){
							if (chance_d(&S, "σ?\n")==0){
								marque = 1;
							}
						}
					}

					if(marque==0){
						w_log(LOG, "[ERROR] Parametres invalides.");
						parameters = setParamLorenz(parameters, B, P, S);
						
					}
					else{
						B = 0;
						P = 0;
						S = 0;
						parameters = setParamLorenz(parameters, B, P, S); // On remplit parameters avec les parametres entrés
					}

                    break;

                case 1: //Van Der Pol 

					if (chance_d(&K, "K?\n")==0){
						if (chance_d(&M, "M?\n")==0){
							if (chance_d(&B, "B?\n")==0){
								if (chance_d(&S, "S?\n")==0){
									if (chance_d(&P, "P?\n")==0){
										if (chance_d(&Q, "Q?\n")==0){
											marque = 1;
										}
									}
								}
								
							}
						}
					}

					if(marque==0){
						w_log(LOG, "[ERROR] Parametres invalides.");
						K=0.02;
						M=4;
						B=0.2;
						S=0.2;
						P=10;
						Q=0.1;
						parameters = setParamVanDerPol(parameters, K,M,B,S,P,Q);
					}

					else{
						parameters = setParamVanDerPol(parameters, K,M,B,S,P,Q); // On remplit parameters avec les parametres entrés
					}

                    printf("\n\t-> K=%f M=%f B=%f S=%f P=%f Q=%f\n",K,M,B,S,P,Q);

                    break;

                case 2: //Rossler
					if (chance_d(&A, "A?\n")==0){
						if (chance_d(&B, "B?\n")==0){
							if (chance_d(&C, "C?\n")==0){
								marque = 1;
							}
						}
					}
					if(marque==0){
						w_log(LOG, "[ERROR] Parametres invalides.");
						A = 0.2;
						B=0.2;
						C=5.7;
						parameters = setParamRossler(parameters, A,B,C);
					}
					else{
						parameters = setParamRossler(parameters, A,B,C); // On remplit parameters avec les parametres entrés
					}
                    printf("\n\t-> A=%f B=%f C=%f\n",A,B,C);
                    break;
                
                default:
                    //Si etrangement aucun mode choisi, ce qui normalement ne devrais jamais arriver, mais on ne sait jamais (oui ce commentaire est trop long)
                    w_log(LOG, "[ERROR] Aucun mode choisi."); 
                    break;
            }
        break;

        case 1: //Parametres par défaut
            w_log(LOG, "Choix des parametres par défaut."); //Ecriture dans le log

            switch(mode){
                case 0: //Lorenz
					B = 8/3;
					P = 28;
					S = 10;
                    parameters = setParamLorenz(parameters, B, P, S); // On remplit parameters avec les parametre par defaut
                    printf("\n\t-> ß=8/3 ρ=28 σ=10\n");
                    break;

                case 1: //Van Der Pol
                    K=0.02;
					M=4;
					B=0.2;
					S=0.2;
					P=10;
					Q=0.1;
					parameters = setParamVanDerPol(parameters, K,M,B,S,P,Q);
                    printf("\n\t-> K=0.02 M=4 B=0.2 S=0.2 P=10 Q=0.1\n");
                    break;

                case 2: //Rossler        
					A = 0.2;
					B=0.2;
					C=5.7;
					parameters = setParamRossler(parameters, A,B,C); // On remplit parameters avec les parametres
                    printf("\n\t-> A=0.2 B=0.2 C=5.7\n");
                    break;
                
                default:
                    //Si on a etrangement aucun mode choisi, ce qui normalement ne devrais jamais arriver, mais on ne sait jamais (oui ce commentaire est trop long)
                    w_log(LOG, "[ERROR] Aucun mode choisi."); 
                    break;
            }

            break;

        default: //Choix inexistant, on ecrit une erreur et on met les parametres par défaut.
            w_log(LOG, "[ERROR] User wants a non-binary system."); 

            switch(mode){
                case 0: //Lorenz
                    B = 8/3;
					P = 28;
					S = 10;
                    parameters = setParamLorenz(parameters, B, P, S); // On remplit parameters avec les parametre
                    printf("\n\t-> B=8/3 P=28 S=10\n");
                    break;

                case 1: //Van Der Pol
                    K=0.02;
					M=4;
					B=0.2;
					S=0.2;
					P=10;
					Q=0.1;
					parameters = setParamVanDerPol(parameters, K,M,B,S,P,Q); // On remplit parameters avec les parametres
                    printf("\n\t-> K=0.02 M=4 B=0.2 S=0.2 P=10 Q=0.1\n");
                    break;

                case 2: //Rossler        
                    A = 0.2;
					B=0.2;
					C=5.7;
					parameters = setParamRossler(parameters, A,B,C); // On remplit parameters avec les parametres
                    printf("\n\t-> A=0.2 B=0.2 C=5.7\n");
                    break;
                
                default:
                    //Si on on etrangement aucun mode choisi, ce qui normalement ne devrais jamais arriver, mais on ne sait jamais (oui ce commentaire est trop long)
                    w_log(LOG, "[ERROR] Aucun mode choisi."); 
                    break;
            }

            break;
    }
    return parameters;
}

void choix_mode(int * mode, char * LOG){
    //Fonction de présentation du projet
    //En bref, un empilement de printf


    printf("\n===============================================================\n");
    printf("================ Modélisation de Trajectoires =================\n");
    printf("===============================================================\n\n\n");
    printf("Bienvenue sur ce projet de modélisation de trajectoire d'un point.\n\n");
    printf("Sont proposés ici, trois attracteurs étranges : \n");
    printf("\t 0. Attracteur de Lorenz\n");
    printf("\t 1. Attracteur de Van Der Pol\n");
    printf("\t 2. Attracteur de Rössler\n");
    printf("\nSelectionnez l'attracteur souhaité en entrant son numéro associé (Par défaut 0).\n");
    
    scanf("%d",mode);

    switch((*mode)){
        case 0:
            w_log(LOG, "Choix de l'attracteur de Lorenz");
            printf("\n\t-> Vous avez choisi l'attracteur de Lorenz");
            break;
        case 1:
            w_log(LOG, "Choix de l'attracteur de Van Der Pol");
            printf("\n\t-> Vous avez choisi l'attracteur de  Van Der Pol");
            break;
        case 2:
            w_log(LOG, "Choix de l'attracteur de Rössler");
            printf("\n\t-> Vous avez choisi l'attracteur de Rössler");
            break;
        default:
            w_log(LOG, "Choix par défaut");
            (*mode) = 0;
            break;
    }

    //Vider le buffer
    vide_buffer();
}

void choix_Tmax(float * Tmax){
	int ch = 0;
    printf("\nNonobstant l'envie de dessiner un attracteur jusqu'à un temps infini, il vous est demandé de fournir un temps d'arrêt.");
    printf("\n\tBien évidemment, nous veillerons a ne pas recevoir un temps trop grand ou nul.");
    printf("\n\tC'est pour celà qu'est fixée une valeur minimum et maximum Tmin = 10s et Tmax = 5000s.\n");
    while(lire_float(Tmax)==1 && ch<CHANCE){
		ch++;
		printf("Tmax : ");
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
			while(lire_double(&x)==1 && ch<CHANCE){
				ch++;
				printf("x?\n");
			}
			if(ch<CHANCE){
				printf("y?\n");
			}
			while(lire_double(&y)==1 && ch<CHANCE){
				ch++;
				printf("y?\n");
			}
			if(ch<CHANCE){
				printf("z?\n");
			}
			while(lire_double(&z)==1 && ch<CHANCE){
				ch++;
				printf("z?\n");
			}
			if (ch>=CHANCE){
				w_log(LOG, "[ERROR] Choix de position non conforme.");
				w_log(LOG, "Position nulle choisie.");
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
                    x = 1;
                    y = 2;
                    z = 3;
                    printf("\n\t-> Position initiale : x=1 y=2 z=3\n",x,y,z);
                    break;

                case 1: //Van Der Pol
                    x = 0.2;
                    y = 0.2;
                    z = 0.2;
                    printf("\n\t-> Position initiale : x=0.2 y=0.2 z=0.2\n",x,y,z);
                    break;

                case 2: //Rossler
                    x = 0;
                    y = 0;
                    z = 0;
                    printf("\n\t-> Position initiale : x=0 y0 z=0\n",x,y,z);
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
