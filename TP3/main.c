/* 
 * File:   main.c
 * Author: akiro
 *
 * Created on November 24, 2014, 4:11 PM
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "entree_sortie.h"
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
void AfficherImage(char* nomFichier){
    char command[40];
    sprintf(command, "eog %s", nomFichier);
    system(command);
}

unsigned char* CreerImage(int largeur, int hauteur){
    unsigned char* p=malloc(largeur*hauteur+15);
    return p;
}

void getBin(int num, char *str)
{
  *(str+5) = '\0';
  int mask = 0x10 << 1;
  while(mask >>= 1)
    *str++ = !!(mask & num) + '0';
}

void Degrade(unsigned char* image, int largeur, int hauteur){
    for (int i=1;i<=largeur*hauteur;i++){
        image[i]=(int)256*i/largeur;
    }
}

void Negatif(unsigned char* image, int largeur, int hauteur){
    for (int i=1;i<=largeur*hauteur;i++){
        image[i]=abs(image[i]-255);
    }
}

int main(int argc, char** argv) {
/*    int a = 2;int b=3;
    char salut[6]="salut";
    char* copie;
    printf("%d \n",a);
    printf("%d \n",Carre1(a));
    printf("%d \n",b);
    Carre2(&b);
    printf("%d \n",b);
    Permut(&a,&b);
    printf("%d \n",a);
    printf("%d \n",b);
    printf("%s \n",salut);
    copie = StringDup(salut);
    printf("%s \n",copie);
    free(copie);*/
    int largeur = 1200;
    int hauteur = 600;
    //::::::::::://::::::::::::::::::::::::::::::::::::::::::
    /*
    unsigned char* y= LireImagePGM("guadalest.pgm",&largeur,&hauteur);
    EcrireImagePGM("guadalest_copie.pgm", y,largeur,hauteur);
    AfficherImage("guadalest_copie.pgm");
    free(y);
     */
    unsigned char* y= CreerImage(largeur,hauteur);
    Degrade(y,largeur,hauteur);
    EcrireImagePGM("degrade.pgm", y,largeur,hauteur);
    AfficherImage("degrade.pgm");
    Negatif(y,largeur,hauteur);
    EcrireImagePGM("negatif.pgm", y,largeur,hauteur);
    AfficherImage("negatif.pgm");
    free(y);
    return (EXIT_SUCCESS);
}


