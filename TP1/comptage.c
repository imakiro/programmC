#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main (int argc, char *argv[]){
	int indices[256]= {0};
	for (int i=1;i<argc;i++){
		int k = strlen(argv[i]);
		int j = 0;
		while (j<k){
			indices[(int)argv[i][j]]++;
			j++;
		}
		if (j!=k)
			indices[32]++;
	}
	// on affiche les caractères
	for (int i = 0;i<256;i++){
		if (indices[i]!=0)
			printf("%c ------ %d \n",i,indices[i]);
	}
	return EXIT_SUCCESS ;
}
