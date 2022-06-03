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

void
prompt(char *ps) {
    fprintf(stderr, "(%s) ^D to exit > ", ps);
}

void
sigint_handler(int signum) {                    
    fprintf(stderr, "Interrupt! (signal number %d)\n", signum);
}

int
main(int argc, char *argv[]) {
    char **argv2= malloc(sizeof(char*)*MAXLINE);
    char line[MAXLINE];
    char *progname = argv[0];
    struct sigaction oldact, newact;
    
    sigaction(SIGINT, NULL, &newact);          
    newact.sa_handler = sigint_handler;
    sigaction(SIGINT, &newact, NULL);          

    for (;;) {
        prompt(progname);
        if (fgets(line, MAXLINE, stdin) == NULL) {

            if (feof(stdin)) {
                break;     
            } else {
                continue;   
            }
        }

        fprintf(stderr, "Will execute command %s", line);
        
        if (linea2argv(line,MAXLINE,argv2) > 0) { 
            pid_t pid;                         
            int wait_status;                   
            fprintf(stderr, "Will fork %s command\n",argv2[0]);
            sigaction(SIGINT, NULL, &oldact); 
            newact = oldact;
            if ((pid = fork()) < 0) {           
                error(0, errno, "fork error\n"); 
            }
            else if (pid == 0) {                 
                newact.sa_handler = SIG_DFL;
                sigaction(SIGINT, &newact, NULL);   
                execvp(argv2[0],argv2);   
                error(EXIT_FAILURE, errno, "execvp error\n"); 
            }
            else {                     
                newact.sa_handler = SIG_IGN;
                sigaction(SIGINT, &newact, NULL);   
                waitpid(pid, &wait_status, 0);
                sigaction(SIGINT, &oldact, NULL);   
                fprintf(stderr, "Ended %s child process\n",argv2[0]);
            }
        }
    }

    fputc('\n', stderr);
    fprintf(stderr, "Exiting %s ...\n", progname);
    exit(EXIT_SUCCESS);
}