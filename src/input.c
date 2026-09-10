#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"

char *read_line(void)
{
    char *line = NULL;
    size_t bufsize = 0;

    if (getline(&line, &bufsize, stdin) == -1)
    {
        if (feof(stdin))
        {
            exit(EXIT_SUCCESS);
        }
        else
        {
            perror("ShellForge");
            exit(EXIT_FAILURE);
        }
    }

    line[strcspn(line, "\n")] = '\0';

    return line;
}
