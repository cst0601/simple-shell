#include "parse.h"

/* parser
 * Replcace space, indent or new line into null
 * link argv into every argument.
 */
void parse(char *line, char **argv)
{
    while (*line != '\0') {     /* not EOLN */
        while (*line == ' ' || *line == '\t' || *line == '\n')
            *line++ = '\0';
        *argv++ = line;
        while (*line != '\0' && *line != ' ' && *line != '\t' && *line != '\n')
            line++;
    }
    *argv = (char*)'\0';
}

void print_argv(char** argv, int limit)
{
    int counter;
    for (counter = 0; counter < limit; ++counter) {
        printf("argv %d =%s|\n", counter, argv[counter]);
    }
    /* check if last is NULL */
    if (argv[limit] == NULL)
        printf("Last in argv is NULL checked.\n");
}
