#include <stdio.h>
#include <stdbool.h>

#include "minish.h"

#define HELP_CD      "cd [..|dir] - cambia de directorio corriente"
#define HELP_DIR     "dir [str]- muestra archivos en directorio corriente, que tengan 'str'"
#define HELP_EXIT    "exit [status] - finaliza el minish con un status de retorno (por defecto 0)"
#define HELP_HELP    "help [cd|dir|exit|help|history|getenv|pid|setenv|status|uid]"
#define HELP_HISTORY "history [N] - muestra los últimos N (10) comandos escritos"
#define HELP_GETENV  "getenv var [var] - muestra valor de variable(s) de ambiente"
#define HELP_PID     "pid - muestra Process Id del minish"
#define HELP_SETENV  "setenv var valor - agrega o cambia valor de variable de ambiente"
#define HELP_STATUS  "status - muestra status de retorno de ultimo comando ejecutado"
#define HELP_UID     "uid - muestra nombre y número de usuario dueño del minish"

int builtin_help(int argc, char **argv){

    int i = 0;
    bool command = false;
    if(argc == 2){
        //Solo un parametro, mostramos todos los comandos:
        while(builtin_arr[i].cmd != NULL && strcmp(builtin_arr[i].cmd, argv[1]) != 0){
            i++;
        }
        if(builtin_arr[i].cmd != NULL){
            printf("%s\n", builtin_arr[i].help_txt);
        }

        return EXIT_SUCCESS;
    }

    else if(argc == 1 || command){
        // Si escribio solo command, o un comando inexistente, imprimomos todos los comandos:
        while(builtin_arr[i].cmd != NULL){
            printf("%s\n", builtin_arr[i].help_txt);
            i++;
        }

        if(argc == 1) return EXIT_SUCCESS;

    }

    fprintf(stderr, "ERROR, too many arguments for function 'help', type 'help help' for more info\n");
    return EXIT_FAILURE; 

}