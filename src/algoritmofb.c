/**
 *  Código para resolver por fuerza bruta  
 * 
 *  @author AAFR 
 *  @date 2019-12-11
 */

#include "rutacg.h"


int generaTodos(void);
unsigned long cantidadPosiblesConv(void);
void recursivaG(int *r,int i);
void insert(int * r);

extern unsigned long dimension;

int *aPobFB=NULL;
int cantidad=0;
int index=0;

/**
 * 
 */
int generaTodos(void){

    cantidad=cantidadPosiblesConv();

    aPobFB =(int *)malloc(sizeof(int)*cantidad+dimension);

    

    for(size_t i=0;i<dimension; i++){
        int r[dimension];
        r[0]=i;
        recursivaG(r,1);
    }



    free(aPobFB);
    return 0;
}

/**
 * 
 */
void recursivaG(int *r,int i){

    if(i==dimension){
        insert(r);
        return;
    }

    int busado = 0;
    for(size_t k=0;k<dimension;k++){
        for(size_t j=0;j<i;j++){
        
            if(*(r+j)==k){
                busado=1;
            }
        }
        if(busado==0){
            *(r+i)=k;
            recursivaG(r,i+1);
        }
        busado=0;
    }

}

/**
 * 
 */
void insert(int * r){

    printf("%d :: ",index);
    for(size_t i =0 ;i<dimension;i++){
       // *(aPobFB+dimension*index+i)=*(r+i);
       printf("%d ",*(r+i));
    }
    printf("\n");

    index++;
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