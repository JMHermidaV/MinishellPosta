#include "minish.h"

char cwd[PATH_MAX];
int globalstatret = 0;
char previous_commands[MAXIMA_LONGITUD_CADENA][MAXLINE]={'\0'};
int cmd_pos = 0;
FILE *history_fp;
 
void
prompt(char *ps) {
    fprintf(stderr, "(%s) %s:%s%s%s ^D to exit > ", ps, getpwuid(geteuid())->pw_name, GREEN ,getcwd(cwd, sizeof(cwd)), WHITE);
}

void
sigint_handler(int signum) {                    
    fprintf(stderr, "Interrupt! (signal number %d)\n", signum);
}

int
main(int argc, char *argv[]) {
    char file_path[PATH_MAX];
    strcpy(file_path,getenv("HOME"));
    strcat(file_path,HISTORY_FILE);
    history_fp = fopen(&file_path[0],"a+");
    /*char *file_path;
    file_path = malloc(sizeof(char)*PATH_MAX);
    //file_path = strdup(getenv('HOME'));
    strcat(file_path,HISTORY_FILE);
    history_fp = fopen(file_path,"a+");*/

    char **argv2= malloc(sizeof(char*)*MAXLINE);
    int argc2 = 0;
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
        
        //fprintf(stderr, "Will execute command %s", line);
        strcpy(previous_commands[cmd_pos],line);
        cmd_pos++;
        argc2 = linea2argv(line, MAXLINE, argv2); 
        if (argc2 > 0) { 
            // Ejecuta el comando
            globalstatret=ejecutar(argc2, argv2);

            /*
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
            */
        }
    }

    fputc('\n', stderr);
    fprintf(stderr, "Exiting %s ...\n", progname);
    exit(EXIT_SUCCESS);
}
