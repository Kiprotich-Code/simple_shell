#include "shell.h"

/**
* _getline - custome getline
* Return: pointer to input
*/
char *_getline()
{
    int a, buffsize = 1024, rd;
    char t = 0;
    char *buff = malloc(buffsize);

    if (buff == NULL)
    {
        free(buff);
        return (NULL);
    }

    for (a = 0; t != EOF && t != '\n'; a++)
    {
        fflush(stdin);
        rd = read(STDIN_FILENO, &t, 1);
        if (rd == 0)
        {
            free(buff);
            exit(EXIT_SUCCESS);
        }
        buff[a] = t;
        if (buff[0] == '\n')
        {
            free(buff);
            return ("\0");
        }
    }
    buff[a] = '\0';
    hashtag_handle(buff);
    return (buff);
}


/**
* hashtag_handle - remove everything after #
* @buff: input;
* Return: void
*/
void hashtag_handle(char *buff)
{
    int a;

    for (a = 0; buff[a] != '\0'; a++)
    {
        if (buff[a] == '#')
        {
            buff[a] = '\0';
            break;
        }
    }
}
