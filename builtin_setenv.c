#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>

#include "minish.h"

int builtin_setenv(int argc, char **argv){

    if(argc == 3){
        return(setenv(argv[1], argv[2], 1));
    }

    else{
    fprintf(stderr, "ERROR al cambiar la variable: %s", argv[1]);
       
        }
    return EXIT_SUCCESS;
    }

    
