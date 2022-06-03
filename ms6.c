// minish - v5 - catch signals on the main loop, completed

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <error.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <ctype.h>


#define MAXLINE 1024

void devolver_memoria(char **argv){
    for (int i=0; argv[i]!=NULL;i++){
                free(argv[i]);
                argv[i]=NULL;
            }
}

/*int linea2argv (char *linea, int argc, char **argv){
    devolver_memoria(argv);
    int i = 0,j = 0,k = 0;
    char word[MAXLINE];
    for(;isspace(linea[i]);i++){
            ;
        }
    while(linea[i] != '\0'){
        for(j = 0; !isspace(linea[i]) && k<argc; i++,j++){
            word[j] = linea[i];
        }
        word[j] = '\0';
        argv[k] = strdup(word);
        k++;
        for(;isspace(linea[i]);i++){
            ;
        }
    }
    return k;
}*/

int linea2argv (char *linea, int argc, char **argv){
    devolver_memoria(argv);
    int i = 0,j = 0,k = 0;
    char word[MAXLINE];
    for(;isspace(linea[i]);i++){
            ;
        }
    while(linea[i] != '\0'){
        if (linea[i] == '"'){
            i++;    //salteo la comilla de apertura
            for(j = 0;  linea[i] != '"' && k<argc; i++,j++){
                word[j] = linea[i];
            }
            i++;    //salteo la comilla de cierre
        }
        else if (linea[i] == "'" ){
            i++;    //salteo la comilla de apertura
            for(j = 0; linea[i] != "'" && k<argc; i++,j++){
                word[j] = linea[i];
            }
            i++;    //salteo la comilla de cierre
        }
        else{
            for(j = 0; !isspace(linea[i]) && k<argc; i++,j++){
                word[j] = linea[i];
            }
        }
        word[j] = '\0';
        argv[k] = strdup(word);
        k++;
        for(;isspace(linea[i]);i++){
            ;
        }
    }
    return k;
}

void
prompt(char *ps) {
    // ps is the prompt string
    fprintf(stderr, "(%s) ^D to exit > ", ps);
}

// ============== NEW CODE HERE ==============
void
sigint_handler(int signum) {                    // the handler for SIGINT
    fprintf(stderr, "Interrupt! (signal number %d)\n", signum);
}

int
main(int argc, char *argv[]) {
    char **argv2= malloc(sizeof(char*)*MAXLINE);
    char line[MAXLINE];
    char *progname = argv[0];
    struct sigaction oldact, newact;
    
    sigaction(SIGINT, NULL, &newact);           // the  previous action for SIGINT is saved in oldact
    newact.sa_handler = sigint_handler;
    sigaction(SIGINT, &newact, NULL);           // set SIGINT handler for loop


    for (;;) {
        prompt(progname);
        if (fgets(line, MAXLINE, stdin) == NULL) {  // EOF
            // ============== NEW CODE HERE ==============
            if (feof(stdin)) {
                break;      // normal EOF, break loop
            } else {
                continue;   // not EOF, read system call was interrupted, continue loop
            }
        }

        fprintf(stderr, "Will execute command %s", line);
        
        if (linea2argv(line,MAXLINE,argv2) > 0) { 
            // very bad technique, only for demo purposes
            // will fork a child to run date command

            pid_t pid;                          // process ID: an unsigned integer type
            int wait_status;                    // wait status will be filled by waitpid syscall

            fprintf(stderr, "Will fork %s command\n",argv2[0]);

            sigaction(SIGINT, NULL, &oldact);   // the  previous action for SIGINT is saved in oldact
            newact = oldact;

            if ((pid = fork()) < 0) {           // fork error, i.e. too many processes
                error(0, errno, "fork error\n"); // will fprintf the error and go on
            }

            else if (pid == 0) {                 // child process
                
                // ============== NEW CODE HERE ==============
                newact.sa_handler = SIG_DFL;
                sigaction(SIGINT, &newact, NULL);   // reset SIGINT default for child

                execvp(argv2[0],argv2);    // if successful, child will go on with new executable
                error(EXIT_FAILURE, errno, "execvp error\n"); // if exec not successful, just exit child
            }

            else {                               // pid > 0: parent (shell) process

                // ============== NEW CODE HERE ==============
                newact.sa_handler = SIG_IGN;
                sigaction(SIGINT, &newact, NULL);   // ignore SIGINT while waiting

                waitpid(pid, &wait_status, 0);

                // ============== NEW CODE HERE ==============
                sigaction(SIGINT, &oldact, NULL);   // restore SIGINT when child finishes

                fprintf(stderr, "Ended %s child process\n",argv2[0]);

                // do something with wait_status
            }
        }
    }

    fputc('\n', stderr);
    fprintf(stderr, "Exiting %s ...\n", progname);
    exit(EXIT_SUCCESS);
}