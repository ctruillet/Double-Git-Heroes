#include <stdio.h>
#include <stdlib.h>
#include "../include/param.h"
#include "../include/log.h"
#include "../include/entrees.h"

#define DT_MAX 0.01
#define DT_MIN 0.0005
#define CHANCES 2


int chance_d(double * lf, char * c){ //chances d'écriture d'un double
	int ch;
	printf("%s",c);
	for(ch=0; lire_double (lf)==0 && ch<CHANCES; ch++){ //si la lecture du double réussie et si l'utilisateur à fais moins de CHANCES erreurs
		printf("%s",c);
	}
	if(ch>=CHANCES){
		return 1;
	}
	return 0;
}
// Structures des parametres

typedef struct Param_Lorenz{
	double B;
	double P;
	double S;
}Param_Lorenz_s;

typedef struct Param_VanDerPol{
	double K;
	double M;
	double B;
	double S;
	double P;
	double Q;
}Param_VanDerPol_s;

typedef struct Param_Rossler{
	double A;
	double B;
	double C;
}Param_Rossler_s;

//Parametres
typedef union Param{
	Param_Lorenz lorenz;
	Param_VanDerPol vanderpol;
	Param_Rossler rossler;
}Param_s;


//Fonctions assignant les parametres du mode choisis dans l'union
Param setLorenz(Param_Lorenz L, Param P){
	P = (Param)malloc(sizeof(Param_s));
	P->lorenz = (Param_Lorenz)L;
	return P;
}

Param setVanDerPol(Param_VanDerPol V, Param P){
	P = (Param)malloc(sizeof(Param_s));
	P->vanderpol = (Param_VanDerPol)V;
		
	return P;
}
 
Param setRossler(Param_Rossler R, Param P){
	P = (Param)malloc(sizeof(Param_s));
	P->rossler = (Param_Rossler)R;
		
	return P;
}

//Recupere les parametres stockés - Lorenz
void get_Param_Lorenz(Param param, double *B, double *P, double *S){
	(*B) = param->lorenz->B;
	(*P) = param->lorenz->P;
	(*S) = param->lorenz->S;
}

//Recupere les parametres stockés - Van Der Pol
void get_Param_VanDerPol(Param param, double *K, double *M, double *B, double *S, double *P, double *Q){
	(*K) = param->vanderpol->K;
	(*M) = param->vanderpol->M;
	(*B) = param->vanderpol->B;
	(*S) = param->vanderpol->S;
	(*P) = param->vanderpol->P;
	(*Q) = param->vanderpol->Q;
}

//Recupere les parametres stockés - Rossler
void get_Param_Rossler(Param param, double *A, double *B, double *C){
	(*A) = param->rossler->A;
	(*B) = param->rossler->B;
	(*C) = param->rossler->C;
}


//set parametres par defaut
/*void setDefParamLorenz(Param  parameters){
	parameters=setParamLorenz( parameters, 8/3, 28, 10);
}

void setDefParamVanDerPol(Param parameters){
	parameters=setVanDerPol(parameters, 0.02, 4, 0.2, 0.2, 10, 0.1);
}

void setDefParamRossler(Param parameters){
	parameters=setRossler(parameters, 0.2, 0.2, 5.7);
}*/


//remplissage des parametres

void choix_dt(float * dt){
	int ch=0;
    printf("\nVoici venu le temps de regler l'increment de temps.");
    printf("\n\tAttention, plus l'increment sera petit, plus les calculs seront nombreux.");
    printf("\n\t dt min = 0.0005s et dt max = 0.01s.\n");
    while(lire_float(dt)==1 && ch<CHANCES){
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

Param setParamLorenz(Param param, double B, double P, double S){
	Param_Lorenz parametersL;
	parametersL = (Param_Lorenz)malloc(sizeof(Param_Lorenz_s));
	
	parametersL->B = B;
	parametersL->P = P;
	parametersL->S = S;

	return setLorenz(parametersL,param);
}

Param setParamVanDerPol(Param param, double K, double M, double B, double S, double P, double Q){

	Param_VanDerPol parametersV;
	parametersV = (Param_VanDerPol)malloc(sizeof(Param_VanDerPol_s));

	parametersV->K = K;
	parametersV->M = M;
	parametersV->B = B;
	parametersV->S = S;
	parametersV->P = P;
	parametersV->Q = Q;

	return setVanDerPol(parametersV,param);

}

Param setParamRossler(Param param, double A, double B, double C){
	Param_Rossler parametersR;
	parametersR = (Param_Rossler)malloc(sizeof(Param_Rossler_s));

	parametersR->A = A;
	parametersR->B = B;
	parametersR->C = C;

	return setRossler(parametersR,param);

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
						w_log(LOG, "reponse <parametres lorenz> invalide");
						parameters = setParamLorenz(parameters, 8/3, 28, 10);
						
					}
					else{
						parameters = setParamLorenz(parameters, B, P, S);  // On remplit parameters avec les parametres entrés
					}
                    break;

                case 1: //Van Der Pol 
					if (chance_d(&K, "K?\n")==0){
						if (chance_d(&M, "M?\n")==0){
							if (chance_d(&B, "B?\n")==0){
								if (chance_d(&S, "S?\n")==0){
									if (chance_d(&P, "P?\n")==0){
										if (chance_d(&Q, "Q?\n")==0){
											marque = 1;                  // si toutes les entrees sont valides set marque à 1
										}
									}
								}
								
							}
						}
					}
					if(marque==0){ //si il y a eu une erreur
						w_log(LOG, "reponse <parametres Van Der Pol> invalide");
						parameters = setParamVanDerPol(parameters, 0.02, 4, 0.2, 0.2, 10, 0.1);  //parametres par defaut
					}
					else{
						parameters = setParamVanDerPol(parameters, K,M,B,S,P,Q); // On remplit parameters avec les parametres entrés
					}

                    printf("\n\t-> K=%f M=%f B=%f S=%f P=%f Q=%f\n",K,M,B,S,P,Q);

                    break;

                case 2: //Rossler
					if (chance_d(&A, "A?\n")==0){
						if (chance_d(&B, "B?\n")==0){
							if (chance_d(&C, "C?\n")==0){              // si toutes les entrees sont valides set marque à 1
								marque = 1;
							}
						}
					}
					if(marque==0){
						w_log(LOG, "reponse <parametres Rossler> invalide");
						parameters = setParamRossler(parameters, 0.2, 0.2, 5.7);
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
                    parameters = setParamLorenz(parameters, 8/3, 28, 10);  // On remplit parameters avec les parametre par defaut
                    printf("\n\t-> ß=1 ρ=2 σ=3\n");
                    break;

                case 1: //Van Der Pol
                    parameters = setParamVanDerPol(parameters, 0.02, 4, 0.2, 0.2, 10, 0.1); // On remplit parameters avec les parametres
                    printf("\n\t-> K=0.02 M=4 B=0.2 S=0.2 P=10 Q=0.1\n");
                    break;

                case 2: //Rossler        
                    parameters = setParamRossler(parameters, 0.2, 0.2, 5.7); // On remplit parameters avec les parametres
                    printf("\n\t-> A=0.2 B=0.2 C=5.7\n");
                    break;
                
                default:
                    //Si on on etrangement aucun mode choisi, ce qui normalement ne devrais jamais arriver, mais on ne sait jamais (oui ce commentaire est trop long)
                    w_log(LOG, "[ERROR] Aucun mode choisi."); 
                    break;
            }

            break;

        default: //Choix inexistant, on ecrit une erreur et on met les parametres par défaut.
            w_log(LOG, "[ERROR] User wants a non-binary system."); 

            switch(mode){
                case 0: //Lorenz
                    parameters = setParamLorenz(parameters, 8/3, 28, 10); // On remplit parameters avec les parametre
                    printf("\n\t-> B=2.66 P=28 S=10\n");
                    break;

                case 1: //Van Der Pol
                    parameters = setParamVanDerPol(parameters, 0.02, 4, 0.2, 0.2, 10, 0.1); // On remplit parameters avec les parametres
                    printf("\n\t-> K=0.02 M=4 B=0.2 S=0.2 P=10 Q=0.1\n");
                    break;

                case 2: //Rossler        
                    parameters = setParamRossler(parameters, 0.2, 0.2, 5.7); // On remplit parameters avec les parametres
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