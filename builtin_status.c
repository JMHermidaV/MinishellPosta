#include "minish.h"

int builtin_status (int argc, char ** argv){
    if (argc != 1){
        fprintf(stderr,"ERROR: Too many input argument");
        return 1;
    }
    else{
        printf("%d\n",globalstatret);
        return 0;
    }
    
}