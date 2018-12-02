#include <stdio.h>


void lol(char *a){
	scanf("%c",a);
}
	


int main(int argc, char*argv[]){
	char c;
	lol(&c);
	printf("%d\n",c);
	return 0;
}
//fksjfskfjsek
