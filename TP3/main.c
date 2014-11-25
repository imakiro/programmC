/* 
 * File:   main.c
 * Author: kuzko
 *
 * Created on November 24, 2014, 4:11 PM
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
/*
 * 
 */
int Carre1(int x){
    return x*x;
}

void Carre2(int* adr_x){
 *adr_x=(*adr_x)*(*adr_x);
}

void Permut(int* adr_a, int* adr_b){
	int temp = *adr_a;
	*adr_a=*adr_b;
	*adr_b=temp;
}

char* StringDup(char* s){
	char* p;
	p = malloc((sizeof(char)*strlen(s)+1));
	if ( p == NULL )
	{
   	  fprintf(stderr,"Allocation impossible \n");
    	  exit(EXIT_FAILURE);
	}else {
	strncpy(p,s,strlen(s)+1);
	}
return p;
}

int main(int argc, char** argv) {
    int a = 2;int b=3;
	char salut[6]="salut";
	
    printf("%d \n",a);
    printf("%d \n",Carre1(a));
    printf("%d \n",b);
	Carre2(&b);
    printf("%d \n",b);
	Permut(&a,&b);
    printf("%d \n",a);
    printf("%d \n",b);
	printf("%s",salut);
	printf("%s",StringDup(salut));
    return (EXIT_SUCCESS);
}


