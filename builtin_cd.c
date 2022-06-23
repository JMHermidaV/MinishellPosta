#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

#include "minish.h"


int builtin_cd(int argc, char **argv){
    // cd [dir], si dir es NULL cambia al directorio de la variable HOME:
    char cwd[PATH_MAX];
    int err = 1;
    if(argc == 2){
        if(strcmp(argv[1], "-") == 0){
            // cd - retorna al directorio anterior
            err = chdir("..");
        }
        else {
            err = chdir(argv[1]);
        }
    }

    else if(argc == 1){
        // Cambio al directorio de HOME
        err = chdir(getenv("HOME"));
    }

    if(err != 0){
        fprintf(stderr, "ERROR: no such file or directory '%s'\n", argv[1]);
        return EXIT_FAILURE;
    }

    // Seteo la variable de ambiente PWD (process working directory)
    setenv("PWD", getcwd(cwd, sizeof(cwd)), 0);

    return EXIT_SUCCESS;
}
