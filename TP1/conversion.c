#include <stdio.h>
#include <stdlib.h>
#include <string.h>
float celsius(int f){
	return (f-32)*(5.0/9.0);
}

int main(){
	printf("---------------------- \n Fahrenheit Celsius \n ---------------------- \n ");
	for (int i=0;i<=200;i+=20){
		float f1 = celsius(i);
		printf("%d ------------ %f \n",i,f1);
	}
return EXIT_SUCCESS ;
}
