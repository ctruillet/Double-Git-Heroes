
#include <stdio.h>
#include "../include/entrees.h"
#include "../include/log.h"





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


