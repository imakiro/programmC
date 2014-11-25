#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Bin2Dec(char bin[], char dec[]){
	int final =0;
	int taille = strlen(bin);
	int puissance = 1;
	for (int i=taille-1;i>=0;i--){
		final+=((bin[i]-'0')*puissance);
		puissance*=2;
	}
	sprintf(dec, "%d", final);	
}


int main (int argc, char *argv[]){
	char s[64] = "" ;
	Bin2Dec(argv[1], s);
	printf("<%s>2 = <%s>10 \n",argv[1],s); 

return EXIT_SUCCESS ;
}
