#include "rutacg.h"

void imprimeSal(double* pdadist);
void imprimePuntos(PPunto pp);

extern unsigned long poblacion;
extern unsigned long dimension;

extern int *aPob;
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

void imprimePuntos(PPunto pp){

}