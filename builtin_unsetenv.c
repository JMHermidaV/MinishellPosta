#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>

#include "minish.h"

int builtin_unsetenv(int argc, char **argv){
    if (argc ==1){
        fprintf(stderr, "%s\n", "ERROR: Not enough input arguments");
        return EXIT_FAILURE;
    }

    for (int i = 1; i<argc; i++){
        if(getenv(argv[i]) == NULL || (unsetenv(argv[i])!=0)){
            return EXIT_FAILURE;
        }
    }
    return EXIT_SUCCESS;
    

}