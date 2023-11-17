#include "shell.h"

/**
 * _atoi - converts a string to an integer
 * @s: string to be converted
 *
 * Description: if the first character is a '+'
 *
 * Return: the int converted from the string
 */
long int _atoi(char *s)
{
	int j, len, k, digit;
	long int m;

	j = 0;
	m = 0;
	len = _strlen(s);
	k = 0;
	digit = 0;

	if (s[j] == '+')
		j++;

	while (j < len && k == 0)
	{
		if (s[j] == '-')
			return (-1);

		if (s[j] >= '0' && s[j] <= '9')
		{
			digit = s[j] - '0';
			m = m * 10 + digit;
			k = 1;
			if (s[j + 1] < '0' || s[j + 1] > '9')
				break;
			k = 0;
		}
		j++;
	}

	if (k == 0)
		return (0);

	if (m > INT_MAX || m < 0)
		return (-1);

	return (m);
}

/**
 * convert - converts number
 * @num: input number
 * @base: input base
 *
 * Description: Create a static buffer
 *
 * Return: result string
 */
char *converts(int num, int base)
{
	static char *rep = "0123456789";
	static char buffer[50];
	char *ptr = NULL;

	ptr = &buffer[49];
	*ptr = '\0';
	do {
		*--ptr = rep[num % base];
		num /= base;
	} while (num != 0);

	return (ptr);
}
