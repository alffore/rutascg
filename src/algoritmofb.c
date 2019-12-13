/**
 *  Código para resolver por fuerza bruta  
 * 
 *  @author AAFR 
 *  @date 2019-12-11
 */

#include "rutacg.h"


int generaTodos(void);
unsigned long cantidadPosiblesConv(void);
void recursivaG(size_t index);

extern unsigned long dimension;

int *aPobFB=NULL;
int cantidad=0;

/**
 * 
 */
int generaTodos(void){

    cantidad=cantidadPosiblesConv();

    aPobFB =(int *)malloc(sizeof(int)*cantidad);

    

    for(size_t i=0;i<dimension; i++){
        recursivaG(i);
    }



    free(aPobFB);
    return 0;
}


void recursivaG(size_t index){
    for(size_t i=0; i<dimension; i++){
        for(size_t j=0; j<=index; j++){
           
        }
    }
    printf("\n");

}


/**
 * 
 */ 
unsigned long cantidadPosiblesConv(void){

    unsigned long aux=1;

    for(size_t i=dimension; i>0; i--){
        aux*=i;
    }

    return aux;
}