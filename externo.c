#include "minish.h"


int externo (int argc, char ** argv){
    struct sigaction oldact, newact;
    pid_t pid;                          // process ID: an unsigned integer type
    int wait_status;                    // wait status will be filled by waitpid syscall

    //fprintf(stderr, "Will fork %s command\n",argv[0]);

    sigaction(SIGINT, NULL, &oldact);   // the  previous action for SIGINT is saved in oldact
    newact = oldact;

    if ((pid = fork()) < 0) {           // fork error, i.e. too many processes
        error(0, errno, "fork error\n"); // will fprintf the error and go on
        return EXIT_FAILURE;
    }

    else if (pid == 0) {                 // child process
        newact.sa_handler = SIG_DFL;
        sigaction(SIGINT, &newact, NULL);   // reset SIGINT default for child
        execvp(argv[0],argv);    // if successful, child will go on with new executable
        fprintf(stderr,"ERROR: execvp error. Comando '%s' no existe\n", argv[0]);
        return EXIT_FAILURE;
        //error(EXIT_FAILURE, errno, "execvp error. %s", argv[0]); // if exec not successful, just exit child

    }
    else {                               // pid > 0: parent (shell) process
        newact.sa_handler = SIG_IGN;
        sigaction(SIGINT, &newact, NULL);   // ignore SIGINT while waiting
        waitpid(pid, &wait_status, 0);
        sigaction(SIGINT, &oldact, NULL);   // restore SIGINT when child finishes
        fprintf(stderr, "Ended %s child process\n",argv[0]);
        // do something with wait_status
        if (WIFSIGNALED(wait_status)!=0){
            return WIFSIGNALED(wait_status);
        }else{
            return WEXITSTATUS(wait_status);
        }
    }
    
 
}