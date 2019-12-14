
#include "../src/rutacg.h"


extern int generaTodos(void);


unsigned long dimension=4;
/**
 *
 * @param cargs
 * @param args
 * @return
 */
int main(int cargs, char **args) {

    if(cargs>=2){
        dimension=atol(*(args+1));
    }

    generaTodos();

    return 0;
}
