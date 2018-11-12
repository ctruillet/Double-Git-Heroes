#include <stdio.h>
#include <stdlib.h>
void lol(int *a){
	scanf("%d",a);
}	
	
int main(int argc, char*argv[]){
	int a=32;
	lol(&a);
	printf("%d\n",a);
	return 0;
}