#include "shell.h"

/**
 * handle_sigint - Doesn't exit on Ctrl-C.
 * @sig: Required for the signal function to run properly.
 *
 * Description: Ignore the signal, print a newline, print the prompt.
 * The call to fflush discards the Ctrl-C.
 */
void handle_sigint(int sig)
{
	(void)sig;
	_putchar('\n');
	print_prompt();
	fflush(stdout);
}

/**
 * release_all - Frees arrays of strings.
 * @args: Array of strings to free.
 */
void release_all(char **args)
{
	int i;

	if (!args)
		return;

	for (i = 0; args[i]; i++)
		free(args[i]);

	free(args);
}

/**
 * handle_line - Handle newline character if found and parse the input line.
 * @line: Line read from stdin.
 * @size: Size of the line returned from getline.
 *
 * Return: Parsed line.
 */
char **handle_line(char *line, int size)
{
	char **parsed_input = NULL;

	if (line[size - 1] == '\n')
		line[size - 1] = '\0';
	parsed_input = _strtok(line, ' ');

	return (parsed_input);
}

