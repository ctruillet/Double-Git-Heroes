#include <stdio.h>
#include <stdlib.h>
#include "../include/param.h"
#include "../include/log.h"
#include "../include/entrees.h"

/*
Derniere modification : 2018-12-09 10:44:12
Par : Valentin
*/

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

//remplissage des parametres
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

//Fonction du choix des parametres
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
                    printf("\"ß ρ σ\"\n");
                    scanf("%lf %lf %lf",&B,&P,&S);
                    printf("\n\t-> B=%f P=%f S=%f\n",B,P,S);
                    parameters = setParamLorenz(parameters, B, P, S); // On remplit parameters avec les parametres entrés

                    break;

                case 1: //Van Der Pol
                    printf("\"K M B S P Q\"\n");
                    scanf("%lf %lf %lf %lf %lf %lf",&K,&M,&B,&S,&P,&Q); 
                    printf("\n\t-> K=%f M=%f B=%f S=%f P=%f Q=%f\n",K,M,B,S,P,Q);

                    parameters = setParamVanDerPol(parameters, K,M,B,S,P,Q); // On remplit parameters avec les parametres entrés
                    break;

                case 2: //Rossler        
                    printf("\"A B C\"\n");
                    scanf("%lf %lf %lf",&A,&B,&C);
                    printf("\n\t-> A=%f B=%f C=%f\n",A,B,C);

                    parameters = setParamRossler(parameters, A,B,C); // On remplit parameters avec les parametres entrés
                    break;
                
                default:
                    //Si on on etrangement aucun mode choisi, ce qui normalement ne devrais jamais arriver, mais on ne sait jamais (oui ce commentaire est trop long)
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


