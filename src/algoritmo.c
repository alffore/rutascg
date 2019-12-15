#include "rutacg.h"

int translocacion_1a1(int *ori, int *des);
int corrimiento_D2I(int *ori, int *des);
int corrimiento_I2D(int *ori, int *des);
int translocacion(int *ori, int *des);
int inversion3(int *ori, int *des);
int insercion(int *ori, int *des);


double calculaDistanciaG2P(int *ap);

int generaPoblacionesMutantes(int *ejemplar);


extern unsigned long poblacion;
extern unsigned long dimension;

extern int *aPob;
extern PPunto aPuntos;

/**
 * Función que calcula la distancia de acuerdo a la ordenación proporcionada
 * @param ap
 * @return
 */
double calculaDistanciaG2P(int *ap){
 double aux=0.0;
 
 double x0 = (aPuntos+*ap)->x;
 double y0 = (aPuntos+*ap)->y;

    for(size_t i = 1 ;i<dimension; i++){
        aux+=sqrt(pow(x0-(aPuntos+*(ap+i))->x,2)+pow(y0-(aPuntos+*(ap+i))->y,2));
        x0=(aPuntos+*(ap+i))->x;
        y0=(aPuntos+*(ap+i))->y;
    }


 return aux;
}

/**
 * Función que calcula la translocación de 2 puntos (intercambio)
 * @param ori
 * @param des
 * @return
 */
int translocacion_1a1(int *ori, int *des) {
    int lower = 0;
    int upper = dimension - 1;

    int num1 = (rand() % (upper - lower + 1)) + lower;
    int num2 = (rand() % (upper - lower + 1)) + lower;

    int i = 0;

    for (i = 0; i < dimension; i++) {
        if (i == num1) {
            *(des + num2) = *(ori + num1);
        } else if (i == num2) {
            *(des + num1) = *(ori + num2);
        } else {
            *(des + i) = *(ori + i);
        }
    }

    return 0;
}

/**
 *
 * @param ori
 * @param des
 * @return
 */
int translocacion(int *ori, int *des) {
    int lower = 0;
    int upper = dimension - 1;

    int m = (rand() % (upper - lower + 1)) + lower;

    for (int i = m; i < dimension; i++) {
        *(des + i - m) = *(ori + i);
    }

    for (int i = 0; i < m; i++) {
        *(des + dimension - 1 - m + i) = *(ori + i);
    }

    return 0;
}


/**
 * Funcion 
 * @param ori
 * @param des
 * @return
 */
int corrimiento_D2I(int *ori, int *des) {

    int i = 0;

    for (i = 1; i < dimension; i++) {
        *(des + i - 1) = *(ori + i);
    }

    *(des + dimension - 1) = *(ori);
    return 0;
}

/**
 *
 * @param ori
 * @param des
 * @return
 */
int corrimiento_I2D(int *ori, int *des) {

    int i = 0;
    int dim = dimension - 1;

    for (i = 0; i < dim; i++) {
        *(des + i + 1) = *(ori + i);
    }

    *(des) = *(ori + dim);
    return 0;
}

/**
 *
 * @param ori
 * @param des
 * @return
 */
int inversion3(int *ori, int *des) {

    int lower = 1;
    int upper = dimension - 2;

    int m = (rand() % (upper - lower + 1)) + lower;

    for (int i = 0; i < dimension; i++) {
        *(des + i) = *(ori + i);
    }

    *(des + m - 1) = *(ori + m + 1);
    *(des + m + 1) = *(ori + m - 1);

    return 0;
}

/**
 *
 * @param ori
 * @param des
 * @return
 */
int insercion(int *ori, int *des) {

    int lower = 0;
    int upper = dimension - 1;

    int c1 = (rand() % (upper - lower + 1)) + lower;
    int c2 = (rand() % (upper - lower + 1)) + lower;

    int cmin = (c1 <= c2) ? c1 : c2;
    int cmax = (c1 > c2) ? c1 : c2;

    int dim_corte=cmax - cmin + 1;
    int temp[dim_corte];

    int dimres = dimension - dim_corte;

    int temp_res[dimres];
    int k = 0;

    for (int i = cmin; i <= cmax; i++) {
        temp[i - cmin] = *(ori + i);
    }

    for (int j = 0; j < dimension; j++) {
        if (j < cmin || j > cmax) {
            temp_res[k] = *(ori + j);
            k++;
        }
    }

    int c3 = (rand() % (dimres - lower)) + lower;

    for (int i = 0; i < dimres; i++) {
        if (i < c3) {
            *(des + i) = temp_res[i];
        } else if (i == c3) {
            for(int k=0;k<dim_corte;k++){
                *(des+i+k)=temp[k];
            }
        } else {
            *(des + i + cmax - cmin) = temp_res[i];
        }
    }

    return 0;
}

/**
 *  Esta función genera las poblaciones mutantes hasta llenar el arreglo 
 *  de poblacion
 */
int generaPoblacionesMutantes(int *ejemplar){
    
    int mutacion=0;

    for(size_t d=0;d<dimension;d++){
        *(aPob+d)=*(ejemplar+d);
    }

    for(size_t p=1;p<poblacion;p++){
        
            mutacion  = (rand() % (numMUTACIONES + 1)) +0;

            switch(mutacion){
                case 0:
                    translocacion_1a1(ejemplar,(aPob+dimension*p));
                    break;
                case 1:
                    corrimiento_D2I(ejemplar,(aPob+dimension*p));
                    break;
                case 2:
                    corrimiento_I2D(ejemplar,(aPob+dimension*p));
                    break;    
                case 3:
                    translocacion(ejemplar,(aPob+dimension*p));
                    break;
                case 4:
                    inversion3(ejemplar,(aPob+dimension*p));
                    break;
                case 5:
                    insercion(ejemplar,(aPob+dimension*p));  
                    break;  
            }
        
    }


    return 0;
}