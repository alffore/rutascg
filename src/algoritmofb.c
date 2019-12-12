/**
 *  Código para resolver por fuerza bruta  
 * 
 *  @author AAFR 
 *  @date 2019-12-11
 */

#include "rutacg.h"


int generaTodos(void);
unsigned long cantidadPosiblesConv();


extern unsigned long dimension;

/**
 * 
 */
int generaTodos(void){



    return 0;
}

/**
 * 
 */ 
unsigned long cantidadPosiblesConv(){

    unsigned long aux=1;

    for(size_t i=dimension; i>0; i--){
        aux*=i;
    }

    return aux;
}