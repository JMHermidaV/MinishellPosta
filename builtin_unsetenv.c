#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>

#include "minish.h"

int builtin_unsetenv(int argc, char **argv){
    if (argc ==1){
        fprintf(stderr, "%s\n", "ERROR: Not enough input arguments");
    }

    for (int i = 1; i<argc; i++){
        unsetenv(argv[i]);
    }
}