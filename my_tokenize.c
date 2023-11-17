#include "shell.h"

/**
 * wordcounts - counts tokens
 * @str: string to
 * @delim: delimeter for tokens
 *
 * Description: loop on string
 *
 * Return: token number
 */
int wordcounts(char *str, char delim)
{
	int num = 0, j;
	int flag = 0;

	for (j = 0; str[j]; j++)
	{
		if (str[j] == delim)
			flag = 0;
		else if (flag == 0)
		{
			flag = 1;
			num++;
		}
	}
	return (num);
}

/**
* _strtok - converts a string
* @str: string tokenizes
* @delim: delimeter for tokens
*
* Description: if the string is NULL, return NULL
*
* Return: pointer to the array
*/
char **_strtok(char *str, char delim)
{
	char *cpy = NULL, **words = NULL;
	int j = 0, n = 0, len = 0, total = 0;

	if (str == 0 || *str == 0)
		return (NULL);
	total = wordcounts(str, delim);
	if (total == 0)
		return (NULL);
	words = malloc(sizeof(char *) * (total + 1));
	if (words == NULL)
		return (NULL);
	while (*str && j < total)
	{
		if (*str == delim)
			str++;
		else
		{
			cpy = str;
			while (*str != delim && *str)
			{
				len++;
				str++;
			}
			words[j] = malloc(sizeof(char) * (len + 1));
			if (!words[j])
				return (NULL);
			while (*cpy != delim && *cpy && *cpy != '\n')
			{
				words[j][n] = *cpy;
				cpy++;
				n++;
			}
			words[j][n] = '\0';
			j++;
			n = 0;
			len = 0;
		}
	}
	words[j] = NULL;
	return (words);
}
