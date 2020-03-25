#include "parser.h"

/* parser
 * Replcace space, indent or new line into null
 * link argv into every argument.
 */
void parser(char *line, char **argv)
{
    while (*line != '\0') {     // not EOLN
        while (*line == ' ' || *line == '\t' || *line == '\n')
            *line++ = '\0';
        *argv++ = line;
        while (*line != '\0' && *line != ' ' && *line != '\t' && *line != '\n')
            line++;
    }
    *argv = '\0';
}
