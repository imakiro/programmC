#include <stdio.h>
#include <stdlib.h>
int main(){
int j;
printf("De quel chiffre voulez vous la table : \n") ; 
scanf("%d", &j);
for (int i=1;i<=10;i++){
printf("%d x %d = %d \n",i,j,i*j);
}
return EXIT_SUCCESS ;}

