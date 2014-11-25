#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main (int argc, char *argv[]){
	int hauteur = atoi(argv[1]);
//	printf("quelle hauteur ? \n") ; 
//	scanf("%d", &hauteur);
	for (int i=1;i<=hauteur;i++){
		for (int j=1;j<=hauteur-i;j++){		
			printf(" ");	
		}
		for (int j=1;j<=(i*2)-1;j++){
			printf("%c",argv[2][0]);
		}
		printf("\n");
	}
return EXIT_SUCCESS ;
}
