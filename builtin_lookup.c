#include <stdlib.h>
#include <string.h>
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

struct builtin_struct builtin_arr[] = {
    {"cd", builtin_cd, HELP_CD},
    {"help", builtin_help, HELP_HELP},
    {"getenv", builtin_getenv, HELP_GETENV},
    {"dir", builtin_dir, HELP_DIR},
    {NULL, NULL, NULL}
};

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
/*
struct builtin_struct builtin_arr[] = {
    {"exit", builtin_exit, HELP_EXIT},
    {"help", builtin_help, HELP_HELP},
    {"history", builtin_history, HELP_HISTORY},
    {"dir", builtin_dir, HELP_DIR},
    {"status", builtin_status, HELP_STATUS},
    {"getenv", builtin_getenv, HELP_GETENV},
    {"setenv", builtin_setenv, HELP_SETENV},
    {"pid", builtin_pid, HELP_PID},
    {"uid", builtin_uid, HELP_UID},
    {"cd", builtin_cd, HELP_CD},
    {NULL, NULL, NULL}
};
*/



