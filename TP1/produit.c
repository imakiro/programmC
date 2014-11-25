#include <stdio.h>
#include <stdlib.h>
int main(){
int j,k;
printf("programme qui multiplie 2 nombres \n saisir un premier nombre :") ; 
scanf("%d", &j);
printf("saisir un deuxieme nombre : ");
scanf("%d", &k);
printf("%d x %d = %d \n", j, k , j*k);
return EXIT_SUCCESS ;}
