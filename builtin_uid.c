#include "minish.h"

int builtin_uid (int argc, char ** argv){
    if (argc == 1){
        struct passwd *pwd = getpwuid(geteuid());
        printf("El user identity es: %d y el nombre es: %s\n", pwd->pw_uid, pwd->pw_name);
        return EXIT_SUCCESS;
    }
    else{
        fprintf(stderr, "UID ERROR: uid does not take arguments\n");
        return EXIT_FAILURE;
    }
    
}