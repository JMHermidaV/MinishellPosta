#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

#include "minish.h"

int builtin_dir(int argc, char **argv){
    // Lista todos los archivos:
    FILE *f;
    if(argc == 1){
        // Solo listo archivos:
        listar("."); 
    }

    else if(argc == 2){
        listar(argv[1]);
    }

    return 0;
}

int listar(char *directory){
    DIR *d;
    struct dirent *dir;
    d = opendir(directory);
    if (d) {
        while((dir = readdir(d)) != NULL) {
            fprintf(stderr, "%s\n", dir->d_name);
        }
    closedir(d);
    }

    else{
        d = opendir(".");
        if(d) {
            strstr(directory, dir->d_name);
            while((dir = readdir(d) != NULL) && strstr(directory, dir->d_name)){
                fprintf(stderr, "%s\n", dir->d_name);
            }
        }
    }

    return 0;
}