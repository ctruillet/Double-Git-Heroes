#include <stdio.h>
#include "../include/entrees.h"
#include "../include/log.h"



void vide_buffer(){
    int c = 0;
    while(c != '\n' && c != EOF){
        c = getchar();
    }
}

void choix_dt(float * dt){
    printf("\nVoici venu le temps de regler l'increment de temps.");
    printf("\n\tAttention, plus l'increment sera petit, plus les calculs seront nombreux.");
    printf("\n\t dt min = 0.0005s et dt max = 0.01s.\n");
    scanf("%f",dt);
    
    if ((*dt) < 0.0005){
        (*dt) = 0.0005;
    }else{
        if ((*dt)>0.01){
            (*dt) = 0.01;
        }
    }
    printf("\n\t-> dt = %.4f s",(*dt));

    vide_buffer(); //on vide le buffer
}


void choix_Tmax(float * Tmax){
    printf("\nNonobstant l'envie de dessiner un attracteur jusqu'à un temps infini, il vous est demandé de fournir un temps d'arrêt.");
    printf("\n\tBien évidemment, nous veillerons a ne pas recevoir un temps trop grand ou nul.");
    printf("\n\tC'est pour celà qu'est fixée une valeur minimum et maximum Tmin = 10s et Tmax = 10000s.\n");
    scanf("%f",Tmax);
    
    if ((*Tmax) < 10){
        (*Tmax) = 10;
    }else{
        if ((*Tmax) > 10000){
            (*Tmax) = 10000;
        }
    }
    printf("\n\t-> Tmax = %.2f s",(*Tmax));

    vide_buffer(); //on vide le buffer
}


Param choix_param(int mode, char * LOG){ 
    Param parameters;
    int defaut = 1;
    double B, P, S;
    double K, M, Q;
    double A, C;

    printf("\n\nRentrons un peu plus dans les détails et choisissons les parametres.\n");
    printf("Voulez-vous les parametres par défaut ?");
    printf("\n\t 0. Non ! J'aime choisir mon mode de vie.");
    printf("\n\t 1. Oui ! J'aurais de plus belles courbes.\n");
    scanf("%d",&defaut);

    switch(defaut){
        case 0:
            w_log(LOG, "Choix des parametres."); //Ecriture dans le log
            printf("\n\nEntrez les parametres sous leurs formes décimale dans le format ");

            switch(mode){
                case 0: //Lorenz
                    printf("\"B P S\"\n");
                    scanf("%lf %lf %lf",&B,&P,&S);
                    printf("\n\t-> B=%f P=%f S=%f\v",B,P,S);
                    parameters = setParamLorenz(parameters, B, P, S); // On remplit parameters avec les parametres entrés

                    break;

                case 1: //Van Der Pol
                    printf("\"K M B S P Q\"\n");
                    scanf("%lf %lf %lf %lf %lf %lf",&K,&M,&B,&S,&P,&Q); 
                    printf("\n\t-> K=%f M=%f B=%f S=%f P=%f Q=%f\v",K,M,B,S,P,Q);

                    parameters = setParamVanDerPol(parameters, K,M,B,S,P,Q); // On remplit parameters avec les parametres entrés
                    break;

                case 2: //Rossler        
                    printf("\"A B C\"\n");
                    scanf("%lf %lf %lf",&A,&B,&C);
                    printf("\n\t-> A=%f B=%f C=%f\v",A,B,C);

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
                    parameters = setParamLorenz(parameters, 8/3, 28, 10); // On remplit parameters avec les parametre
                    printf("\n\t-> B=2.66 P=28 S=10\v");
                    break;

                case 1: //Van Der Pol
                    parameters = setParamVanDerPol(parameters, 0.02, 4, 0.2, 0.2, 10, 0.1); // On remplit parameters avec les parametres
                    printf("\n\t-> K=0.02 M=4 B=0.2 S=0.2 P=10 Q=0.1\v");
                    break;

                case 2: //Rossler        
                    parameters = setParamRossler(parameters, 0.2, 0.2, 5.7); // On remplit parameters avec les parametres
                    printf("\n\t-> A=0.2 B=0.2 C=5.7\v");
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
                    printf("\n\t-> B=2.66 P=28 S=10\v");
                    break;

                case 1: //Van Der Pol
                    parameters = setParamVanDerPol(parameters, 0.02, 4, 0.2, 0.2, 10, 0.1); // On remplit parameters avec les parametres
                    printf("\n\t-> K=0.02 M=4 B=0.2 S=0.2 P=10 Q=0.1\v");
                    break;

                case 2: //Rossler        
                    parameters = setParamRossler(parameters, 0.2, 0.2, 5.7); // On remplit parameters avec les parametres
                    printf("\n\t-> A=0.2 B=0.2 C=5.7\v");
                    break;
                
                default:
                    //Si on on etrangement aucun mode choisi, ce qui normalement ne devrais jamais arriver, mais on ne sait jamais (oui ce commentaire est trop long)
                    w_log(LOG, "[ERROR] Aucun mode choisi."); 
                    break;
            }

            break;
    }

    vide_buffer(); //on vide le buffer
    return parameters;
}

Coord choix_position(int mode, char * LOG){
    double x,y,z;
    int defaut = 1;

    // On demande d'abord si on veut les valeurs par défaut ou non
    printf("\n\nIl est maintenant temps de selectionner la position initiale.\n");
    printf("\t 0. Je suis un(e) aventurier(e) et je veux explorer mon attracteur ! (choix de la position initiale)\n");
    printf("\t 1. J'aime rester dans les sentiers battus (position initiale par défaut)\n");
    scanf("%d",&defaut);

    vide_buffer(); //on vide le buffer

    switch(defaut){
        case 0: // Cas choix de la position
            w_log(LOG, "Choix de la position initiale."); //Ecriture dans le log

            printf("\nEntrez la position initiale dans le format \"x y z\"\n");
            scanf("%lf %lf %lf",&x,&y,&z);
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
                    printf("\n\t-> Position initiale : x=0.2 y=0.2 z=0.2\n");
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
    return new_coord(0, x, y, z);;
}

void choix_mode(int * mode, char * LOG){
    //Fonction de présentation du projet
    //En bref, un empilement de printf


    printf("===============================================================\n");
    printf("================ Modélisation de Trajectoires =================\n");
    printf("===============================================================\n\v\n");
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

