#include "shell.h"

/**
* _strdups - allocate memory for a str
* @str: string to duplicate
*
* Return: new string on success, NULL on failure
*/

char *_strdup(char *str)
{
	char *dup = NULL;
	int c, j = 0;

	if (!str)
		return (NULL);

	while (str[j])
		j++;

	dup = malloc(sizeof(char) * j + 1);

	if (!dup)
		return (NULL);

	for (c = 0; c < j; c++)
		dup[c] = str[c];

	dup[c] = '\0';

	return (dup);
}

/**
 * str_concat - concatenates two strings,
 * and allocate memory for string
 * @s1: string to concatenate
 * @s2: other string
 *
 * Return: pointer to the string
 */
char *str_concat(char *s1, char *s2)
{
	char *s3 = NULL;
	unsigned int j = 0, k = 0, len1 = 0, len2 = 0;

	len1 = _strlen(s1);
	len2 = _strlen(s2);

	s3 = malloc(sizeof(char) * (len1 + len2 + 1));
	if (s3 == NULL)
		return (NULL);

	j = 0;
	k = 0;

	if (s1)
	{
		while (j < len1)
		{
			s3[j] = s1[j];
			j++;
		}
	}

	if (s2)
	{
		while (j < (len1 + len2))
		{
			s3[j] = s2[k];
			j++;
			k++;
		}
	}
	s3[j] = '\0';

	return (s3);
}

/**
 * _strcmps - compares two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: less than 0
 * more than 0 if s1 is greater than s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
		{
			return (0);
		}
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/**
* _strncmps - compare strings
* @s1: string 1
* @s2: string 1
* @n: number of bytes to compare
*
* Return: 0 if the strings are different
*/
int _strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int j = 0;

	while (*s1 == *s2 && j < n)
	{
		if (*s1 == '\0')
		{
			return (0);
		}
		s1++;
		s2++;
		j++;
	}
	return (j != n);
}
