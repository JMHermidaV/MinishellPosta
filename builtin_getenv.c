#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>

#include "minish.h"

int builtin_getenv(int argc, char **argv){
    // Imprime las variables de entorno pasadas:
    int i;

    if(argc <= 1){
        fprintf(stderr, "%s\n", "ERROR: Not enough input arguments");
        return -1; // Debe pasar al menos una variable de entorno
    }

    for(i = 1; argv[i] != NULL; i++){
        // Buscamos en cada iteracion la variable de entorno
        
        if(getenv(argv[i]) != NULL){
            fprintf(stderr, "%s: %s\n", argv[i], getenv(argv[i]));
        } // En error, retorna NULL:
        else{
            fprintf(stderr, "BUILTIN_ GETENV ERROR: invalid variable name '%s'\n", argv[i]);
            return -1;
        }
    }

    return 0;
}