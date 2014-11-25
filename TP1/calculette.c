#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main (int argc, char *argv[]){
	if (argv[2][0]=='+')
		printf("%d + %d = %d \n",atoi(argv[1]),atoi(argv[3]),atoi(argv[1])+atoi(argv[3]));
	else if (argv[2][0]=='x')
		printf("%d x %d = %d \n",atoi(argv[1]),atoi(argv[3]),atoi(argv[1])*atoi(argv[3]));
	else if (argv[2][0]=='/')
		printf("%d / %d = %d \n",atoi(argv[1]),atoi(argv[3]),atoi(argv[1])/atoi(argv[3]));
	else if (argv[2][0]=='-')
		printf("%d - %d = %d \n",atoi(argv[1]),atoi(argv[3]),atoi(argv[1])-atoi(argv[3]));
	else 
		printf("nan mais vous m'avez pris pour texas instruments?\n rentrez un des 4 opérateurs éssentiels : \n + - x / \n");
return EXIT_SUCCESS ;
}
