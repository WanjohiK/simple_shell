#include "shell.h"

/**
 * sigint_handlers - doesn't exit in case of Ctrl-C
 * @sig: required for signal function
 *
 * Description: ignore sig, print newline
 */
void sigint_handlers(int sig)
{
	(void)sig;
	 _putchar('\n');
	 print_prompts();
	 fflush(stdout);
}

/**
 * free_everythings - arrays of strings
 * @args: array of strings to free
 */
void free_everythings(char **args)
{
	int j;

	if (!args)
		return;

	for (j = 0; args[j]; j++)
		free(args[j]);

	free(args);
}

/**
* parse_lines - handle newline character
* @line: line read from stdin
* @get: size of line returned
*
* Return: parsed line
*/
char **parse_lines(char *line, int get)
{
	char **input = NULL;

	if (line[get - 1] == '\n')
		line[get - 1] = '\0';
	input = _strtoks(line, ' ');

	return (input);
}
