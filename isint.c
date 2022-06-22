#include "minish.h"

int isint(char *argv){                                  //loops through characters checking they are numeric 
    for(int i = 0; argv[i]!='\0';i++){
        if (!isdigit(argv[i])){
            return 0;
        }
    }
    return 1;
}

