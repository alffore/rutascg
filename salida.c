#include "rutacg.h"

extern void imprimeSal(void);


void imprimeSal(double * pdadist){
    

    for(size_t p=0;p<poblacion;p++){
        for(size_t d=0;d<dimension;d++){
            printf("%d ", *(aPob+dimension*p+d));
        }
        printf(":: %lf\n",)
    }
}