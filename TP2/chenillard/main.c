/* 
 * File:   main.c
 * Author: kuzko
 *
 * Created on November 3, 2014, 4:04 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
//#define ON '*'
//#define OFF '.'
#define ON '1'
#define OFF '0'
#define NBAMPOULES 10
#define TEMPORISATION 50
//typedef unsigned char          interrupteurs_t ;
//typedef unsigned short int     interrupteurs_t ;
//typedef unsigned int           interrupteurs_t ;
typedef unsigned long int      interrupteurs_t ;
//typedef unsigned long long int interrupteurs_t ;
//------------------------------------------------------------------------------

void Temporisation(int n)
//------------------------------------------------------------------------------
// Fonction qui met n milli-secondes a s'executer
// C'est donc une temporisation de n ms
// necessite <stdio.h>
{
    clock_t start, stop;

    n = n * CLOCKS_PER_SEC / 1000; // clock() ne fonctionne pas forcement en milli-secondes
    start = clock(); // Top depart. start = l'heure de depart
    stop = start + n; // stop = l'heure de fin

    while (clock() < stop) // On scrute l'heure tant qu'on n'a pas atteint la fin
    {
    }
}

/*------------------------------------------------------------------------------
int main()
//------------------------------------------------------------------------------
// petit programme qui teste la fonction Temporisation
{
        int i ;

        printf("Je compte toutes les secondes jusqu'a 5 :\n") ;
        for (i=1; i<6; i++)
        {
                Temporisation(1000) ;	// 1000ms = 1 sec.
                printf("\r%d ", i) ; 
                fflush(stdout) ;
        }
        printf("\nFini !\n") ;

        return EXIT_SUCCESS ;
} 
 */

/*
 * CHENILLARD V1
 * int main(int argc, char** argv) {
    char chenillard[NBAMPOULES+1];
    
    while (1) {
        for (int i = 0; i < NBAMPOULES; i++) {
            chenillard[i] = OFF;
        }
        chenillard[NBAMPOULES]='\0';
        for (int i = 0; i < NBAMPOULES; i++) {
            if (i == 0) {
                chenillard[i] = ON;
            } else {
                chenillard[i - 1] = OFF;
                chenillard[i] = ON;
            }
            printf("\r %s", chenillard);
            fflush(stdout);
            Temporisation(TEMPORISATION);
        }
    }


    return (EXIT_SUCCESS);
}
 * 
/*
 * CHENILLARD V2 
int main(int argc, char** argv) {
    int nbamp, timer;
    char all,ete;
    if (argc == 9){ 
        for (int i=1;i<argc;i+=2){
            printf(argv[i]);
            printf("\0");
            if (argv[i][1]=='a'){
                all=argv[i+1][0];
            }else if (argv[i][1]=='e'){
                ete=argv[i+1][0];
            }else if (argv[i][1]=='n'){
                nbamp=atoi(argv[i+1]);
            }else if (argv[i][1]=='t'){
                timer=atoi(argv[i+1]);
            }else {
                printf("vous avez passé un argument non reconnu (a,e,n ou t) \0");
            }
        }
    } else if (argc == 1) {
    //lancement non parametré
        all=ON;
        ete=OFF;
        timer=TEMPORISATION;
        nbamp=NBAMPOULES;
    } else {
    printf("merci de donner le nombre de paramètres nécessaire");
    return (EXIT_FAILURE);
}

char chenillard[nbamp + 1];

while (1) {
    for (int i = 0; i < nbamp; i++) {
        chenillard[i] = ete;
    }
    chenillard[nbamp] = '\0';
    for (int i = 0; i < nbamp; i++) {
        if (i == 0) {
            chenillard[i] = all;
        } else {
            chenillard[i - 1] = ete;
                    chenillard[i] = all;
        }
        printf("\r %s", chenillard);
                fflush(stdout);
                Temporisation(timer);
    }
}


return (EXIT_SUCCESS);
}
 */
/*  CHENILLARD 2 corrigé
int main(int argc, char** argv) {
    int nbamp, timer;
    char all, ete;
            //lancement non parametré
        all = ON;
        ete = OFF;
        timer = TEMPORISATION;
        nbamp = NBAMPOULES;
    if (argc > 2 && argc % 2!=0) {
        for (int z = 1; z < argc; z += 2) {
            if (argv[z][1] == 'a') {
                all = argv[z + 1][0];
            } else if (argv[z][1] == 'e') {
                ete = argv[z + 1][0];
            } else if (argv[z][1] == 'n') {
                nbamp = atoi(argv[z + 1]);
            } else if (argv[z][1] == 't') {
                timer = atoi(argv[z + 1]);
            } else {
                printf("vous avez passé un argument non reconnu (a,e,n ou t) \0");
            }
        }
    } else {
        printf("merci de donner un nombre de paramètres correct");
        return (EXIT_FAILURE);
    }

    char chenillard[nbamp + 1];

    while (1) {
        for (int i = 0; i < nbamp; i++) {
            chenillard[i] = ete;
        }
        chenillard[nbamp] = '\0';
        for (int i = 0; i < nbamp; i++) {
            if (i == 0) {
                chenillard[i] = all;
            } else {
                chenillard[i - 1] = ete;
                chenillard[i] = all;
            }
            printf("\r %s", chenillard);
            fflush(stdout);
            Temporisation(timer);
        }
    }


    return (EXIT_SUCCESS);
}
*/
void Dec2Bin(char dec[], char bin[]){
	int decimal = atoi(dec);
	int valeur=32768; //2^15
	for (int i=0;i>=15;i++){
		float temp = (float)decimal;
		if (temp/valeur > 1){
			decimal/=2;
			bin[i]='1';
		}else {
		bin[i]='0';
		}
		valeur/=2;
	}
}



interrupteurs_t Compteur(interrupteurs_t inter) {
    return inter+0x01;
}

int ValeurAmpoule(interrupteurs_t inter, int i) {
/*   int final ;
    interrupteurs_t masque=0x01;
    for (int z=1;z<i;z++){
        masque = masque<<1;
    }
    if (inter & masque >0){
        final=1;
    }else{
        final=0;
    }
    return (final);
 */
    interrupteurs_t masque=0x01;
    if (inter & (masque <<i)){
        return 1;
    }else{
        return 0;
    }
}

unsigned char Inversion(interrupteurs_t inter){
    inter = ~inter ;
    return inter;
}

interrupteurs_t RotationGauche(interrupteurs_t inter) {
    interrupteurs_t masque=0x01;
    int tmp =0;
    masque = masque << ((8*sizeof(inter))-1);
//    printf("%d        \0",masque);
 //   fflush(stdout);
    if (inter & masque){
        tmp=1;
    }
    inter = inter << 1;
    if (tmp)
    inter +=1;
    
    return inter;
}

/*interrupteurs_t RotationGauche(interrupteurs_t interrupteur){
	int i = 1;
	int limite =sizeof(interrupteurs_t);
	if(interrupteur >= (limite/2)+1)
	{
		interrupteur = (interrupteur - limite/2);
		interrupteur = (interrupteur << i);
		interrupteur = interrupteur + 1;
	}
	else
		interrupteur = interrupteur << i;
	return interrupteur;
}*/


int main(int argc, char** argv) {
    int nbamp, timer;
    char all, ete;
    interrupteurs_t inter; // les interrupteurs qui pilotent les ampoules
    unsigned char rampe[8*sizeof(interrupteurs_t)+1]={0}; // les ampoules que l'on affiche
            //lancement non parametré
        all = ON;
        ete = OFF;
        timer = TEMPORISATION;
        nbamp = NBAMPOULES;
        inter = 0x03;
//        fflush(stdout);
//       return (EXIT_SUCCESS);
    if ( argc % 2!=0) {
        for (int z = 1; z < argc; z += 2) {
            if (argv[z][1] == 'a') {
                all = argv[z + 1][0];
            } else if (argv[z][1] == 'e') {
                ete = argv[z + 1][0];
/*            } else if (argv[z][1] == 'n') {
                nbamp = atoi(argv[z + 1]);*/
            } else if (argv[z][1] == 't') {
                timer = atoi(argv[z + 1]);
            } else {
                printf("vous avez passé un argument non reconnu (a,e,n ou t)");
                fflush(stdout);
            }   
        }
    } else {
        printf("merci de donner un nombre de paramètres correct");
        return (EXIT_FAILURE);
    }

//    char chenillard[nbamp + 1];

    while (1) {
/*        for (int i = 0; i < nbamp; i++) {
            chenillard[i] = ete;
        }
        chenillard[nbamp] = '\0';
        for (int i = 0; i < nbamp; i++) {
            if (i == 0) {
                chenillard[i] = all;
            } else {
                chenillard[i - 1] = ete;
                chenillard[i] = all;
            }
            printf("\r %s", chenillard);
            fflush(stdout);
            Temporisation(timer);
        }
    
        for (int i = 0; i < nbamp; i++) {
            rampe[i] = ete;
        }*/
        int etat;
        for (int i=0;i<8*sizeof(interrupteurs_t);i++){
            etat = ValeurAmpoule(inter,i);
            if (etat==1){
                rampe[8*sizeof(interrupteurs_t)-i-1] = all;
            }else{
                rampe[8*sizeof(interrupteurs_t)-i-1] = ete;
            }
        }
//        printf("\r %d", inter);
        printf("\r %s", rampe);
        fflush(stdout);
        Temporisation(timer);
//        inter=Inversion(inter);
//        inter=Compteur(inter);
        inter=RotationGauche(inter);
    }


    return (EXIT_SUCCESS);
}