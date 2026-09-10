#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"

#define TOKEN_SIZE 64

char **parse_line(char *line)
{
    int bufsize = TOKEN_SIZE;
    int position = 0;
    char **tokens;
    char *token;

    tokens = malloc(bufsize * sizeof(char *));

    if (tokens == NULL)
    {
        perror("ShellForge");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, " \t");

    while (token != NULL)
    {
        tokens[position] = token;
        position++;

        if (position >= bufsize)
        {
            bufsize += TOKEN_SIZE;

            tokens = realloc(tokens, bufsize * sizeof(char *));

            if (tokens == NULL)
            {
                perror("ShellForge");
                exit(EXIT_FAILURE);
            }
        }

        token = strtok(NULL, " \t");
    }

    tokens[position] = NULL;

    return tokens;
}

void free_tokens(char **tokens)
{
    free(tokens);
}
