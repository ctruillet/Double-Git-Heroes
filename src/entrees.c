#include <stdio.h>
#include "../include/entrees.h"
#include "../include/log.h"



void vide_buffer(){
    int c = 0;
    while(c != '\n' && c != EOF){
        c = getchar();
    }
}


void choix_param(int mode, char * LOG){
    Param parameters;
    float B, P, S;
    float K, M, Q;
    float A, C;
    w_log(LOG, "Choix des parametres."); //Ecriture dans le log


    printf("\nRentrons un peu plus dans les détails et choisissons les parametres.\n");
    printf("Entrez les parametres dans le format ");

    switch(mode){
        case 0: //Lorenz
            printf("\"B P S\"\n");
            scanf("%f %f %f",&B,&P,&S);

            setParamLorenz(parameters, B, S, P); // On remplit parameters avec les parametres entrés

            break;

        case 1: //Van Der Pol
            printf("\"K M B S P Q\"\n");
            scanf("%f %f %f %f %f %f",&K,&M,&B,&S,&P,&Q); 

            setParamVanDerPol(parameters, K,M,B,S,P,Q); // On remplit parameters avec les parametres entrés
            break;

        case 2: //Rossler        
            printf("\"A B C\"\n");
            scanf("%f %f %f",&A,&B,&C);

            setParamRossler(parameters, A,B,C); // On remplit parameters avec les parametres entrés
            break;
        
        default:
            //Si on on etrangement aucun mode choisi, ce qui normalement ne devrais jamais arriver, mais on ne sait jamais (oui ce commentaire est trop long)
            w_log(LOG, "[ERROR] Aucun mode choisi."); 
            break;
    }

    vide_buffer(); //on vide le buffer
}

Coord choix_position(int mode, char * LOG){
    float x,y,z;
    int pos_init = 1;

    // On demande d'abord si on veut les valeurs par défaut ou non
    printf("\n\nIl est maintenant temps de selectionner la position initiale.\n");
    printf("\t 0. Je suis un(e) aventurier(e) et je veux explorer mon attracteur ! (choix de la position initiale)\n");
    printf("\t 1. J'aime rester dans les sentiers battus (position initiale et parametres par défaut)\n");
    scanf("%d",&pos_init);

    vide_buffer(); //on vide le buffer

    switch(pos_init){
        case 0: // Cas choix de la position
            w_log(LOG, "Choix de la position initiale."); //Ecriture dans le log

            printf("\nEntrez la position initiale dans le format \"x y z\"\n");
            scanf("%f %f %f",&x,&y,&z);

            printf("\n\t-> Position initiale entrée : x=%.2f y=%.2f z=%.2f\n",x,y,z);

            vide_buffer(); //on vide le buffer

            choix_param(mode, LOG);

        break;

        case 1: //Cas valeur par défaut
            w_log(LOG, "Position initiale par défaut.");

            switch(mode){
                case 0: //Lorenz
                    x = 1;
                    y = 2;
                    z = 3;
                    break;

                case 1: //Van Der Pol
                    x = 0.2;
                    y = 0.2;
                    z = 0.2;
                    break;

                case 2: //Rossler
                    x = 0;
                    y = 0;
                    z = 0;
                    break;
            }

            break;

        default:
            w_log(LOG, "Position nulle choisie");
            x = 0;
            y = 0;
            z = 0;
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
    printf("===============================================================\n\n");
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

