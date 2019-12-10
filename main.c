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
int corrimiento_I2D(int *ori, int *des);
int translocacion(int *ori, int *des);
int inversion3(int *ori, int *des);


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
            *(des+num2) = *(ori+num1);
        }else if(i==num2){
            *(des+num1) = *(ori+num2);
        }else{
            *(des+i) = *(ori+i);
        }
    }

    return 0;
}


int translocacion(int *ori, int *des){
    int lower =0;
    int upper=dimension-1;
    
    int  m = (rand() %(upper - lower + 1)) + lower;

    for(int i=m;i<dimension;i++){
        *(des+i-m)=*(ori+i);
    }

    for(int i=0;i<m;i++){
        *(des+dimension-1-m+i) = *(ori+i);
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
        *(des+i-1) = *(ori+i);
    }

    *(des+dimension-1) = *(ori);
    return 0;
}


int corrimiento_I2D(int *ori, int *des){

    int i=0;
    int dim=dimension-1;

    for(i=0;i<dim;i++){
        *(des+i+1) = *(ori+i);
    }

    *(des)=*(ori+dim);
    return 0;
}


int inversion3(int *ori, int *des){

    int lower =1;
    int upper=dimension-2;
    
    int  m = (rand() %(upper - lower + 1)) + lower;

    for(int i=0;i<dimension;i++){
        *(des+i) = *(ori+i);
    }

    *(des+m-1) = *(ori+m+1);
    *(des+m+1) = *(ori+m-1);

    return 0;
}


int insercion(int *ori, int *des){

    int lower =0;
    int upper=dimension-1;

    int c1 = (rand() %(upper - lower + 1)) + lower;
    int c2 = (rand() %(upper - lower + 1)) + lower;

    int cmin =(c1<=c2)?c1:c2;
    int cmax =(c1 > c2)?c1:c2;

    int temp[cmax-cmin+1];

    int dimres=dimension-cmax+cmin-1;

    int temp_res[dimres];
    int k=0;

for(int i=cmin;i<=cmax;i++){
    temp[i-cmin]=*(ori+i);
}

for(int j=0;j<dimension;j++){
    if(j<cmin || j>cmax){
        temp_res[k]=*(ori+j);
        k++;
    }
}

int c3 = (rand() %(dimres - lower)) + lower;

    for(int i=0;i<dimres;i++){
        if(i<c3){
            *(des+i)=temp_res[i];
        }else if(i==c3{

        }else{
            *(des+i+cmax-cmin)=temp_res[i];
        }
    }

    return 0;
}