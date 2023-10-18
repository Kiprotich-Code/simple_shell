#include "shell.h"
#include <stdio.h>

/**
* exec - funcyion to execute commands
* @argv: list of tokens
* @copy: copy of buffer
* @state: to know if its interactive or non interacive
* Return: void
*/
void exec(char **argv, char *copy, int state)
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
perror("");
}
else
{
wait(NULL);
free(copy);
free(argv);
if (state == 2)
exit(1);
prompt(1);
}
}
