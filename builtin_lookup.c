#include <stdlib.h>
#include <string.h>
#include "minish.h"

struct builtin_struct *builtin_lookup(char *cmd){
    struct builtin_struct *funcion;
    int i;
    for(i = 0; builtin_arr[i].cmd != NULL && strcmp(cmd,builtin_arr[i].cmd)!=0;i++){
        ;    
    }
    if(builtin_arr[i].cmd == NULL){
        funcion = NULL;
    }else{
        funcion = &builtin_arr[i];
    }
    return funcion;
}
