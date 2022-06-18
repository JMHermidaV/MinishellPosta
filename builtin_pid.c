#include <stdio.h>
#include <string.h>
#include "minish.h"

int builtin_pid (int argc, char ** argv){
    if(argc ==1){
        printf("%d\n", getpid());
        return 0; 
    }
    else{
        printf("BUILTIN_PID ERROR: pid does not take arguments\n");
        return 1;
    }
}