#include "shell.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void free_all(char *copy, char **env_cpy, char *path);

/**
* find - find path and execute
* @argv: char array of input
* @copy: copy of buffer
* @state: keep track of state
* Return: void
*/
void find(char **argv, char *copy, int state)
{
int a = 0;
char *key = "PATH";
char **env_cpy = NULL;
char *token = NULL;
char *path = NULL;
char *msg = ": not found\n";
struct stat st;

if (strcmp(argv[0], "exit") == 0)
{
if (argv[1])
exit(_atoi(argv[1]));
exit(0);
}
while (environ[a])
a++;
env_cpy = malloc(sizeof(char *) * a);
for (a = 0; environ[a]; a++)
env_cpy[a] = strdup(environ[a]);
env_cpy[a] = NULL;
a = 0;
while (env_cpy[a])
{
token = strtok(env_cpy[a++], "=");
if (strcmp(key, token) == 0)
break;
}

token = strtok(NULL, "\0");
token = strtok(token, ":");
while (token)
{
path = malloc(sizeof(char) * (strlen(token) + strlen(copy) + 1));
strcat(path, token), strcat(path, "/"), strcat(path, copy);
if (stat(path, &st) == 0)
{
argv[0] = strdup(path);
exec(argv, copy, state);
}
token = strtok(NULL, ":");
}
char *g = _strcat(argv[0], msg);
write(1, g, _strlen(g));
free_all(copy, env_cpy, path);
}
/**
* free_all - free allocated spaces and call prompt again
* @copy: par 1
* @env_cpy: par 2
* @path: par 3
* Return: void
*/
void free_all(char *copy, char **env_cpy, char *path)
{
free(copy);
free(env_cpy);
free(path);
prompt(1);
}
