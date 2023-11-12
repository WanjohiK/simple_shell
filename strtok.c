#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100

/**
 * splitString - Splits a string into words based on a delimiter using strtok.
 * @str: The input string to be split (modified by strtok).
 * @delim: The delimiter used to split the string.
 *
 * Return:
 * An array of strings, where each element is a word from the input string.
 *         The last element of the array is NULL.
 */
char **splitString(char *str, const char *delim)
{
	int i = 0;
	char *strCopy, *token, **wordsArray = malloc(MAX_WORDS * sizeof(char *));

	if (wordsArray == NULL)
	{
		perror("Memory allocation error");
		exit(EXIT_FAILURE);
	}
	strCopy = strdup(str); /*Duplicate the original string*/

	if (strCopy == NULL)
	{
		perror("Memory allocation error");
		exit(EXIT_FAILURE);
	}
	token = strtok(str, delim); /*Tokenize the duplicate string*/

	while (token != NULL)
	{
		/**Allocate memory for each word separately using strdup*/
		wordsArray[i] = strdup(token);
		if (wordsArray[i] == NULL)
		{
			perror("Memory allocation error");
			exit(EXIT_FAILURE);
		}
		i++;
		if (i == MAX_WORDS)
		{
			fprintf(stderr, "Max number of words exceeded\n");
			exit(EXIT_FAILURE);
		}

		token = strtok(NULL, delim);
	}
	wordsArray[i] = NULL; /*Set the last element to NULL*/
	free(strCopy); /*Free the duplicate string*/

	return (wordsArray);
}

/**
 * main - Entry point of the program.
 *
 * Return: Always 0.
 */
int main(void)
{
	char input[] = "Hello, World! This is a sample string.";
	const char *delimeter = " ";
	char **wordsArray = splitString(input, delimeter);
	int i;

	for (i = 0; wordsArray[i] != NULL; i++)
	{
		printf("Word %d: %s\n", i + 1, wordsArray[i]);
	}

	for (i = 0; wordsArray[i] != NULL; i++)
	{
		free(wordsArray[i]);
	}
		free(wordsArray);

		return (0);
}
