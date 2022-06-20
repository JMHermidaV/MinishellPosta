#include "minish.h"

void devolver_memoria(char **argv){
    for (int i=0; argv[i]!=NULL;i++){
                free(argv[i]);
                argv[i]=NULL;
            }
}