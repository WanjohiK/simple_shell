#include <stdio.h>
#include <stdlib.h>

/**
 * main - This is the Entry point of the program.
 *
 *  Description: Prints "$ ", waits for the user to enter a command
 *  and then prints it to the next line.
 *
 *  Return:
 *  Always 0, indicating success.
 */

int main(void)
{
	char *line = NULL;
	size_t len = 0;

	printf("$ ");

	ssize_t read = getline(&line, &len, stdin);

	if (read != -1)
	{
		printf("%s", line);
	}
	else
	{
		fprintf(stderr, "Error reading input\n");
	}

	free(line);

	return (0);
}
