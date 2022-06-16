#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

#include "minish.h"

int builtin_dir(int argc, char **argv){
    // Lista todos los archivos:
    if(argc == 1){
        DIR *d;
        int x;
        struct dirent *dir;
        struct stat *fs;
        fs = malloc(sizeof(struct stat*));
        d = opendir(".");
        if (d) {
            while((dir = readdir(d)) != NULL) {
                x = stat("ejecutar.o", fs);
                //x = stat(dir->d_name, fs);
                //printf("%s\n", dir->d_name);
                if(x == -1){
                    // Error
                    perror(errno);
                    return 8;
                }
                else{}
                    //printf("%d - %s - %ld - %ld - %s \n",fs->st_mode, getpwuid(fs->st_uid)->pw_name, fs->st_ino, fs->st_ctime, dir->d_name);
                }
            }
            closedir(d);
        }
    }

    else if(argc == 2){
        //listar(argv[1]);
    }

    return 0;
}

