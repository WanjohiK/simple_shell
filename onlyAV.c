#include <stdio.h>

/**
 * main - Entry point of the program.
 * @argc: Number of Command-line arguments.
 * @argv: Array of command-line arguments.
 *
 * Description: Prints Command-line arguments without using argc.
 *
 * Return: ALways 0 (Success).
 *
 */

int main(int argc, char *argv[])
{
	int i = 0;

	while (argv[i] != NULL)
	{
		printf("%s\n", argv[i]);
		i++;
	}
	return (0);
}
