#include "minish.h"
void print_history(int n){
    if (cmd_pos+1<n){           //Estoy en el caso en que tengo que acceder al archivo pq con los que tengo en memoria no me da.
        int size_to_print = 0, lines = 0;
        struct stat hf_st;
        char *file_commands;
        char file_path[PATH_MAX];
        strcpy(file_path,getenv("HOME"));
        strcat(file_path,HISTORY_FILE); 
        stat(file_path,&hf_st);
        file_commands = mmap(NULL,hf_st.st_size,PROT_READ,MAP_PRIVATE,fileno(history_fp),0);
        for(int i = hf_st.st_size; i!=0 && lines!=n-cmd_pos;i--){
            if(file_commands[i] == '\n'){
                lines++;
            }
            size_to_print++;
        }
        printf("%.*s",size_to_print,file_commands+hf_st.st_size-size_to_print);
        print_history(cmd_pos);
    }
    else{                       //Con los que tengo en memoria me alcanza
        for(int i=cmd_pos-n;printf("%s",previous_commands[i]);i++); //Imprimo los últimos n comandos
    }
}

int builtin_history (int argc, char ** argv){
    int n;
    if (argc==1){
        n = 10;                                 //Default value of n
    }
    else if (argc == 2){
        if(isint(argv[1])==1){                  //valid argument
            n = atoi(argv[1]);
        }
        else{                                   //invalid argument
            fprintf(stderr,"ERROR: argument %s not valid: Numeric argument required.\n",argv[1]);
            return EXIT_FAILURE;
        }
    }
    else{                                       //too many arguments
        fprintf(stderr,"ERROR: history can only receive 0 or 1 arguments. Type 'help history' for more information.\n");
        return EXIT_FAILURE;
    }
    
    print_history(n);
    return EXIT_SUCCESS;
}

