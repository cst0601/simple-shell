#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parse.h"
#include "execute.h"

#define BUFFER_SIZE     1024
#define ARG_VEC_SIZE    64

int main (int argc, char * argv[]) {
    char input_line[BUFFER_SIZE];
    char *arg_vec[ARG_VEC_SIZE];

    while (1) {
        printf("chikuma@TEST csh $ ");
        if (fgets(input_line, BUFFER_SIZE, stdin) != NULL) {
            parse(input_line, arg_vec);
            if (strcmp(arg_vec[0], "exit") == 0) {
                exit(0);
            }
            execute(arg_vec);
        }
    }

    return 0;
}
