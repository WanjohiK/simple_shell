#include "shell.h"

/**
 * _strlen - length of a string
 * @s: string to evaluate
 *
 * Return: length of string
 */
int _strlen(char *s)
{
	int len = 0;

	if (!s)
		return (0);
	while (s[len])
		len++;
	return (len);
}

/**
 * *_strcpy - string pointer
 * @dest: pointer to the buffer in which we copy the string
 * @src: string to be copied
 *
 * Return: the pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int len, j;

	len = 0;

	while (src[len] != '\0')
		len++;

	for (j = 0; j < len; j++)
		dest[j] = src[j];

	dest[j] = '\0';

	return (dest);
}
