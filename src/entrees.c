#include <stdio.h>
#include "../include/entrees.h"
#include "../include/log.h"

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
    printf("\nSelectionnez l'attracteur souhaité en entrant son numéro associé (Par défaut 0).\n\n");
    
    scanf("%d",mode);

    switch((*mode)){
        case 0:
            w_log(LOG, "Choix de l'attracteur de Lorenz");
            break;
        case 1:
            w_log(LOG, "Choix de l'attracteur de Van Der Pol");
            break;
        case 2:
            w_log(LOG, "Choix de l'attracteur de Rössler");
            break;
        default:
            w_log(LOG, "Choix par défaut");
            (*mode) = 0;
            break;
    }

    //Vider le buffer
    vide_buffer();
}

void vide_buffer(){
    int c = 0;
    while(c != '\n' && c != EOF){
        c = getchar();
    }
}