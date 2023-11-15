#include "shell.h"

/**
 * _putchar - writees charcater c
 * @c: This is the chracter to be printed
 *
 * Return: if successful return 1 and -1 if error
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}


/**
 * print_prompt - helps print prompt
 */
void print_prompt(void)
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
	int i;

	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
	_putchar('\n');
}
