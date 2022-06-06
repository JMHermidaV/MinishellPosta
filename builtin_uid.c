#include <stdlib.h>
#include <string.h>
#include "minish.h"

int builtin_uid (int argc, char ** argv){
    struct passwd *pwd = getpwuid(geteuid());
    printf("El user identity es: %d y el nombre es: %s\n", pwd->pw_uid, pwd->pw_name);
    return 0;
}