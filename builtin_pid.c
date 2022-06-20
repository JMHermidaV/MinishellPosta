#include <stdio.h>
#include <string.h>
#include "minish.h"

int builtin_pid (int argc, char ** argv){
    if(argc ==1){
        printf("%d\n", getpid());
        return EXIT_SUCCESS; 
    }
    else{
        fprintf(stderr,"BUILTIN_PID ERROR: pid does not take arguments\n");
        return EXIT_FAILURE;
    }
}