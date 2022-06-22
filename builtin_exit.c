#include "minish.h"
int builtin_exit (int argc, char ** argv){
    for(int i = 0;i<cmd_pos;i++){
        fprintf(history_fp,previous_commands[i]);
        //printf("%s - %s",history_fp[0],previous_commands[i]);
    }
    fclose(history_fp);
    if (argc == 1) {
        devolver_memoria(argv);
        exit(globalstatret);
    }
    else if (argc == 2){
        if(isint(argv[1])==1){
            int x = atoi(argv[1]);
            devolver_memoria(argv);
            exit(x);     
        }else{
            fprintf(stderr, "Exit can receive only integers as argument\n");
            devolver_memoria(argv);
            exit(EXIT_FAILURE);
        }
    }
    else{
        fprintf(stderr, "Exit can receive only 0 or 1 arguments\n");
        devolver_memoria(argv);
        exit(EXIT_FAILURE);
    }
}

