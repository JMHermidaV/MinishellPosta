#include <stdio.h>
#include <string.h>
#include "minish.h"
#include "builtin_lookup.c"
#include "externo.c"

int ejecutar (int argc, char **argv){
    struct builtin_struct *bstruct;
    int retorno;
    bstruct = builtin_lookup(argv[0]);              //Llamo a Lookup 
    if(bstruct!=NULL){                              //Si no es un builtin
        retorno = externo(argc,argv);               //Ejecuto externo
    }
    else{                                           //Si es un builtin
        retorno = bstruct->func(argc,argv);         //Ejecuto la función
    }
    return retorno;                                     
}