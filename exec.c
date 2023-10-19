#include "shell.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

/* Declare the prompt function */
void prompt(int state);

extern char **environ;  /* Declare environ */

/**
* exec - function to execute commands
* @argv: list of tokens
* @copy: copy of buffer
* @state: to know if it's interactive or non-interactive
* Return: void
*/
void exec(char **argv, const char *copy, int state)
{
pid_t child_pid;
int status;

child_pid = fork();
if (child_pid == -1)
{
perror("fork failed");
exit(EXIT_FAILURE);
}
if (child_pid == 0)
{
if (execve(argv[0], argv, environ) == -1)
perror("execve");
}
else
{
wait(&status);
free((char *)copy);
free(argv);
if (state == 2)
exit(1);
/* Assuming that prompt is declared and defined in another part of your code */
prompt(1);
}
}
