//
// Created by alfonso on 06/12/19.
//
/**
 * https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm
 *
 */





#include "rutacg.h"


int generadorPuntos(void);
int liberaPuntos(void);
int generaPoblaciones(void);


extern int translocacion_1a1(int *ori, int *des);
extern int corrimiento_D2I(int *ori, int *des);
extern int corrimiento_I2D(int *ori, int *des);
extern int translocacion(int *ori, int *des);
extern int inversion3(int *ori, int *des);
extern double calculaDistancias(PPunto pp);
extern void imprimeSal(double* pdadist);


unsigned long dimension; //cantidad de Puntos
double tamXY = 500;

unsigned long poblacion; //cantidad de ejemplos
unsigned int ciclos = 10; //cantidad de iteraciones

int *aPob; //areglo en memoria para la poblaciones
PPunto aPuntos; //arreglo de puntos (coordenadas e id)

/**
 *
 * @param cargs
 * @param args
 * @return
 */
int main(int cargs, char **args) {

    dimension = 5;
    poblacion = 120;

    aPob=NULL;

    srand(time(NULL));   // Initialization, should only be called once.


    generadorPuntos();

   
    generaPoblaciones();



    liberaPuntos();


    return 0;
}

/**
 *
 * @param pp
 * @return
 */
int generadorPuntos(void) {

    double x,y;

    aPuntos= (PPunto) malloc(sizeof(struct PUNTO) * dimension);

    for (size_t i = 0; i < dimension; i++) {
        (aPuntos+i)->x =((double)rand()/(double)(RAND_MAX)) * tamXY;
        (aPuntos+i)->y=((double)rand()/(double)(RAND_MAX)) * tamXY;
        (aPuntos+i)->id = i;
    }


    return 0;
}

/**
 *
 * @param pp
 * @return
 */
int liberaPuntos(void) {

    free(aPuntos);

    return 0;
}

/**
 * 
 */
int generaPoblaciones(void){

    double adist[poblacion];

    for(size_t i=0 ; i<poblacion ; i++){
        adist[i]=-1.0;
    }

    aPob = (int *)malloc(sizeof(int)*poblacion*dimension);

    for(size_t p=0;p<poblacion;p++){
        for(size_t d=0;d<dimension;d++){
            *(aPob+dimension*p+d)=d;
        }
    }

    imprimeSal(adist);
    free(aPob);
}


