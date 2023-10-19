#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>

/* Function prototypes */
char *_strcpy(char *dest, const char *src);
int _strlen(const char *s);
int _atoi(const char *s);
char *_strcat(char *dest, const char *src);
void free_all(char *copy, char **env_cpy, char *path);
char *_getline(void);
void hashtag_handle(char *buff);
void tokenizer(char *buffer, int state);
void find(char **argv, const char *copy, int state);
void exec(char **argv, const char *copy, int state);
void free_all(char *copy, char **env_cpy, char *path);

#endif
