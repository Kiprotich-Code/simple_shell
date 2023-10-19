#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
* copy_buffer - Create a copy of the input buffer.
* @buffer: Input from the user.
* Return: The copied buffer.
*/
char *copy_buffer(const char *buffer)
{
    char *copy = strdup(buffer);
    if (copy == NULL)
    {
        exit(0);
        /* No need to free buffer in this case */
    }
    return (copy);
}

/**
* count_arguments - Count the number of arguments in the buffer.
* @buffer: Input buffer.
* Return: The number of arguments.
*/
int count_arguments(const char *buffer)
{
    int argc = 0;
    char *token = strtok(strdup(buffer), " \n");
    while (token)
    {
        token = strtok(NULL, " \n");
        argc++;
    }
    return (argc);
}

/**
* tokenize_arguments - Tokenize the input buffer and store arguments in argv.
* @buffer: Input buffer.
* @argv: Argument vector to store arguments.
* @argc: Number of arguments.
*/
void tokenize_arguments(const char *buffer, char **argv, int argc)
{
    int a = 0;
    char *token = strtok(strdup(buffer), " \n");
    while (token)
    {
        argv[a] = strdup(token);
        token = strtok(NULL, " \n");
        a++;
    }
    argv[a] = NULL;
}

/**
* tokenizer - Tokenize the input buffer.
* @buffer: Input from the user.
* @state: Used to track the state.
* Return: void
*/
void tokenizer(char *buffer, int state)
{
    char **argv = NULL;
    struct stat st;

    char *copy = copy_buffer(buffer);
    int argc = count_arguments(buffer);
    argv = malloc(sizeof(char *) * (argc + 1));

    if (argv == NULL)
    {
        free(copy);
        exit(0);
    }

    tokenize_arguments(copy, argv, argc);
    free(copy);

    if (argv[0][0] == '/' && stat(argv[0], &st) == 0)
    {
        exec(argv, argv[0], state);
    }
    else
    {
        find(argv, argv[0], state);
    }
}
