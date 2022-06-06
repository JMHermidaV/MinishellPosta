#include "minish.h"
int builtin_gid (int argc, char ** argv){
    printf("El grupo principal es: %d\n", getgid());
}