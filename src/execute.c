#include "execute.h"

void execute(char **argv)
{
    pid_t pid;
    int status;

    char out[100];

    if ((pid = fork()) < 0) {                   /* process create failed */
        sprintf(out, "*** ERROR: exec failed\n");
        write(1, out, strlen(out));
        exit(1);
    }
    else if (pid == 0) {
        if (execvp(*argv, argv) < 0) {
            sprintf(out, "*** ERROR: exec failed\n");
            write(1, out, strlen(out));
            exit(1);
        }
    }
    else {
        while (wait(&status) != pid)
            ;
    }
}
