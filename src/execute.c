#include "execute.h"

void execute(char **argv)
{
    pid_t pid;
    int status;
    if ((pid = fork()) < 0) {                   /* process create failed */
        printf("*** ERROR: exec failed\n");
        exit(1);
    }
    else if (pid == 0) {
        if (execvp(*argv, argv) < 0) {
            printf("*** ERROR: exec failed\n");
            exit(1);
        }
    }
    else {
        while (wait(&status) != pid)
            ;
    }
}
