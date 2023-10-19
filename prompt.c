#include "shell.h"

/**
* prompt - Prompt the user for input.
* @state: Check the state to determine the mode.
* Return: None.
*/
void prompt(int state)
{
    char *buffer = NULL;

    if (state == 1)
    {
        write(1, "My shell by Mary : ", 12);
    }
    buffer = _getline();

    /* Use the appropriate mode for tokenization based on the state */
    if (state == 1)
        tokenizer(buffer, 1);
    else
        tokenizer(buffer, 2);
}
