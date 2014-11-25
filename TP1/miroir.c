#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
char ch1[64] = "bonjour" ;
char ch2[64] = "xxxxxxxxxxxxxxxxx" ;
int j=0,i=strlen(ch1)-1;
while(i>=0){
	ch2[j]=ch1[i];
	j++;i--;
}
ch2[j]='\0';
printf("%s \n",ch2);
return EXIT_SUCCESS ;}

