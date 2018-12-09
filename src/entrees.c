
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

int lireFinL(){//lit la fin de la ligne aprèes une saisie
	char c=getchar();
	int i=0;
	while(c!='\n'){ //tant que la saisie n'a pas été entièrement consommée
		c=getchar();
		i++;
	}
	return(i);
}

void vide_buffer(){
    int c = 0;
    while(c != '\n' && c != EOF){//tant que la saisie n'a pas été entièrement consommée
        c = getchar();
    }
}


//lecture sécurisée en fonction du format attendue 
int lire_format(const char * c, void * n){
	int lu=scanf(c, n);
	int nb=lireFinL();
	
	if(lu!=1 || nb>0){ //si le scanf detecte une erreur ou si la ligne n'est pas entierement consommée
		return 1;
	}
	else{
		return 0;
	}
}


int lire_int(int * d){
	const char * c="%d";
	if(lire_format(c, d)==1){//si il y a une erreur de lecture
		return 1;
	}
	return 0;
}

int lire_float(float * f){
	const char * c="%f";
	if(lire_format(c, f)==1){//si il y a une erreur de lecture
		return 1;
	}
	return 0;
}

int lire_double(double * lf){//si il y a une erreur de lecture
	const char * c="%lf";
	if(lire_format(c, lf)==1){
		return 1;
	}
	return 0;
}

int lire_chaine(char * s){
	const char * c="%s";
	if(lire_format(c, s)==1){//si il y a une erreur de lecture
		return 1;
	}
	return 0;
}

//octroie de nouvelles chances de saisie lorque l'utilisatuer se trompe sur le format d'un double
int chance_d(double * lf, char * c){
	int ch;
	printf("%s ",c);
	for(ch=0; lire_double (lf)==1 && ch<CHANCE; ch++){//tant que l'utilisateur se trompe et a des essais
		printf("%s ",c);
	}
	if(ch>=CHANCE){//si l'utilisateur a consommé toutes ses chances
		return 1;
	}
	return 0;
}

//Fonction de choix de dt
void choix_dt(float * dt){
	int ch=0;

    printf("\nVoici venu le temps de regler l'increment de temps.");
    printf("\n\tAttention, plus l'increment sera petit, plus les calculs seront nombreux.");
    printf("\n\t dt min = 0.0005s et dt max = 0.01s.\n");

    printf("dt : ");
	
    while(lire_float(dt)==1 && ch<CHANCE){
		ch++;
		printf("dt : ");
	}
    
    if ((*dt) < DT_MIN){ //Permet d'avoir dt dans l'intervalle DT_MIN DT_MAX
        (*dt) = DT_MIN;
    }else{
        if ((*dt)>DT_MAX){
            (*dt) = DT_MAX;
        }
    }
    printf("\n\t-> dt = %.4fs \n",(*dt));
}



void choix_Tmax(float * Tmax){
	int ch = 0;
    printf("\nNonobstant l'envie de dessiner un attracteur jusqu'à un temps infini, il vous est demandé de fournir un temps d'arrêt.");
    printf("\n\tBien évidemment, nous veillerons a ne pas recevoir un temps trop grand ou nul.");
    printf("\n\tC'est pour celà qu'est fixée une valeur minimum et maximum Tmin = 10s et Tmax = 5000s.\n");

    printf("Tmax : ");

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
    printf("\n\t-> Tmax = %.2fs",(*Tmax));
}


