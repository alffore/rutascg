#include "rutacg.h"

void imprimeSal(double* pdadist);
void imprimePuntos(PPunto pp);
void imprimePuntovI(int j);
void imprimeSecuenciaPuntos(int *pp);

extern unsigned long poblacion;
extern unsigned long dimension;

extern int *aPob;
extern PPunto aPuntos;

/**
 * 
 */
void imprimeSal(double* pdadist){

    for(size_t p=0;p<poblacion;p++){
        for(size_t d=0;d<dimension;d++){
            printf("%d ", *(aPob+dimension*p+d));
        }
        printf(":: %lf\n",*(pdadist+p));
    }

}

/**
 * 
 */
void imprimePuntos(PPunto pp){

    for(size_t i=0;i<dimension; i++){
        printf("%ld %lf %lf\n",i,(pp+i)->x,(pp+i)->y);
    }

}

/**
 * Función que imprime un punto de acuerdo al indice
 * 
 */
void imprimePuntovI(int j){
    PPunto pp=(aPuntos+j*dimension);
    for(size_t i=0;i<dimension; i++){
        printf("%ld %lf %lf\n",i,(pp+i)->x,(pp+i)->y);
    }
}

void imprimeSecuenciaPuntos(int *pp){

    for(size_t i = 0 ;i<dimension; i++){
        printf("%d ",*(pp+i));
    }
    printf("\n");

}