#include "shell.h"

/**
 * _putchar - writees charcater c
 * @c: This is the chracter  printed
 *
 * Return: if successful
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}


/**
 * print_prompts - helps print prompt
 */
void print_prompts(void)
{
	char *s = "$ ";

	write(1, s, 2);
}

/**
 * _puts - prints string
 * @str: pointer to string
 */
void _puts(char *str)
{
	int j;

	for (j = 0; str[j] != '\0'; j++)
		_putchar(str[j]);
	_putchar('\n');
}
