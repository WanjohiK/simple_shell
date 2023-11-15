#include "shell.h"

/**
 * customPutchar - writes the character c to standard output
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int customPutchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * printPrompt - prints a prompt for the shell
 */
void printPrompt(void)
{
	char *s = "$ ";

	write(1, s, 2);
}

/**
 * customPuts - prints a string to standard output
 * @str: pointer to the string to print
 */
void customPuts(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		customPutchar(str[i]);
	customPutchar('\n');
}

