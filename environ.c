#include "shell.h"

/**
 * customSetenv - sets an environment variable,
 * handles the setenv builtin
 * @head: double pointer to the environ linked list
 * @argv: name and value of the variable to set
 * @args: number of arguments
 *
 * Description: If the list is empty, return NULL
 * If no arguments are passed to setenv,
 * print the list
 * If too many arguments are passed, return -1
 * Concatenate the first argument with an '='
 * and the second argument
 * Find the index of the name we're looking for
 * If not found, add the variable at the end
 * Else delete the node at the index, and add the new string
 *
 * Return: 0 on success, -1 on failure
 */
int customSetenv(env_t **head, char **argv, int args)
{
	char *buf1 = NULL, *buf2 = NULL;
	int index = 0;

	if (!head || !*head)
		return (0);

	if (args != 3)
		return (-1);

	buf1 = customStrConcat(argv[1], "=");
	buf2 = customStrConcat(buf1, argv[2]);
	free(buf1);

	index = find_index_list(*head, argv[1]);
	if (index == 0)
	{
		add_node_end(head, buf2);
		free(buf2);
		return (0);
	}

	if (index > 0)
	{
		delete_node_at_index(head, index);
		add_node_at_index(head, buf2, index);
		free(buf2);
		return (0);
	}

	free(buf2);
	return (0);
}

/**
 * customUnsetenv - unsets an environment variable,
 * handles the unsetenv builtin
 * @head: double pointer to the environ linked list
 * @argv: array of strings, includes parsed line
 *
 * Description: If no arguments are passed, return -1
 * Find the index of the variable, delete it
 *
 * Return: 0 on success, -1 on failure
 */
int customUnsetenv(env_t **head, char **argv)
{
	int index;

	if (!argv[1])
		return (-1);

	index = find_index_list(*head, argv[1]);
	if (index == 0 || !head || !*head)
		return (0);

	else
		delete_node_at_index(head, index);

	return (0);
}

/**
 * setenvHandler - handles the setenv and unsetenv builtins
 * @argv: array of arguments from the command line
 * @head: pointer to the env_t linked list
 * @i: index of the command in history
 * @progName: name of the program
 *
 * Description: Count the number of arguments
 * If setenv, call customSetenv, print error on failure
 * If unsetenv, call customUnsetenv, print error on failure
 */
void setenvHandler(char **argv, env_t **head, int *i, char *progName)
{
	int n = 0, m = 0, args = 0;
	char *unsetErr = "unsetenv: Too few arguments.\n";

	while (argv[args])
		args++;

	if (!customStrCmp(argv[0], "setenv"))
	{
		n = customSetenv(head, argv, args);
		if (n == -1)
			printErrorSetenv(i, progName, argv);
	} else if (!customStrCmp(argv[0], "unsetenv"))
	{
		m = customUnsetenv(head, argv);
		if (m == -1)
			write(2, unsetErr, customStrlen(unsetErr));
	}
}

/**
 * printErrorSetenv - prints a custom error message for setenv
 * @i: index of the command in history
 * @s: name of the program
 * @argv: array of arguments from the command line
 *
 * Description: Concatenate strings to format the error message
 * Free previous concatenation at every new string
 * When the string is completed, write the message to standard error
 */
void printErrorSetenv(int *i, char *s, char **argv)
{
	char *buf1 = NULL, *buf2 = NULL, *buf3 = NULL, *buf4 = NULL, *buf5 = NULL;
	char *number = NULL;

	number = convert(*i, 10);

	buf1 = customStrConcat(s, ": ");
	buf2 = customStrConcat(buf1, number);
	free(buf1);
	buf3 = customStrConcat(buf2, ": ");
	free(buf2);
	buf4 = customStrConcat(buf3, argv[0]);
	free(buf3);
	buf5 = customStrConcat(buf4, ": Bad variable name\n");
	free(buf4);
	write(2, buf5, customStrlen(buf5));
	free(buf5);
}

