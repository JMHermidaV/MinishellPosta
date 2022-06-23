#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>

#include "minish.h"

int builtin_getenv(int argc, char **argv){
    // Imprime las variables de entorno pasadas:
    int i;

    if(argc <= 1){
        fprintf(stderr, "%s\n", "ERROR: Not enough input arguments, type 'help getenv' for more info");
        return EXIT_FAILURE; // Debe pasar al menos una variable de entorno
    }

    for(i = 1; argv[i] != NULL; i++){
        // Buscamos en cada iteracion la variable de entorno
        
        if(getenv(argv[i]) != NULL){
            printf("%s: %s\n", argv[i], getenv(argv[i]));
        } // En error, retorna NULL:
        else{
            fprintf(stderr, "GETENV ERROR: invalid variable name for input '%s'\n", argv[i]);
            return EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS;
}