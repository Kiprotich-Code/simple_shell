#include "shell.h"

/**
* _strcpy - Copies the string from src to dest.
* @dest: Destination string.
* @src: Source string.
* Return: Pointer to dest.
*/
char *_strcpy(char *dest, const char *src)
{
int i = 0;
while (src[i] != '\0')
{
dest[i] = src[i];
i++;
}
dest[i] = '\0';
return (dest);
}

/**
* _strlen - Returns the length of a string.
* @s: String to measure.
* Return: Length of the string.
*/
int _strlen(const char *s)
{
int length = 0;
while (s[length] != '\0')
{
length++;
}
return (length);
}

/**
* _atoi - Converts a string to an integer.
* @s: String to convert.
* Return: The converted integer value.
*/
int _atoi(const char *s)
{
int i = 0;
int sign = 1;
int result = 0;

if (s[0] == '-')
{
sign = -1;
i = 1;
}

while (s[i] >= '0' && s[i] <= '9')
{
result = result * 10 + (s[i] - '0');
i++;
}

return (sign *result);
}

/**
* _strcat - Concatenates two strings.
* @dest: Destination string.
* @src: Source string.
* Return: Pointer to dest.
*/
char *_strcat(char *dest, const char *src)
{
char *ret = dest;
while (*dest)
{
dest++;
}
while (*src)
{
*dest++ = *src++;
}
*dest = '\0';
return (ret);
}
