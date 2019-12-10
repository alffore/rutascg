//
// Created by alfonso on 06/12/19.
//
/**
 * https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm
 *
 */



#include <stdlib.h>
#include <stdio.h>
#include <time.h>


#include "rutacg.h"


dimension = 5;

int generadorPunto(void);
int translocacion1a1(int *ori, int *des);
int corrimiento_D2I(int *ori, int *des);



/**
 *
 * @param cargs
 * @param args
 * @return
 */
int main(int cargs, char **args){

    srand(time(NULL));   // Initialization, should only be called once.





    return 0;
}


int generadorPunto(void){

    return 0;
}


/**
 * Función que calcula la translocación de 2 puntos (intercambio)
 * @param ori
 * @param des
 * @return
 */
int translocacion1a1(int *ori, int *des){
    int lower =0;
    int upper=dimension-1;

    int num1 = (rand() %(upper - lower + 1)) + lower;
    int num2 = (rand() %(upper - lower + 1)) + lower;

    int i=0;

    for(i=0;i<dimension;i++){
        if(i==num1){
            *(des+num2)=*(ori+num1);
        }else if(i==num2){
            *(des+num1)=*(ori+num2);
        }else{
            *(des+i)=*(ori+i);
        }
    }

    return 0;
}

/**
 * Funcion 
 * @param ori
 * @param des
 * @return
 */
int corrimiento_D2I(int *ori, int *des){

    int i=0;


    for(i=1;i<dimension;i++){
        *(des+i-1)=*(ori+i);
    }

    *(des+dimension-1)=*(ori);
    return 0;
}
