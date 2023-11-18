#include "shell.h"

/**
 * _setenv - sets an environment
 * @head: double pointer
 * @argv: name and val
 * @args: number of ar
 *
 * Description: If the list
 *
 * Return: 0 on success, -1 on failure
 */
int _setenv(env_t **head, char **argv, int args)
{
	char *buf1 = NULL, *buf2 = NULL;
	int index = 0;

	if (!head || !*head)
		return (0);

	if (args != 3)
		return (-1);

	buf1 = str_concat(argv[1], "=");
	buf2 = str_concat(buf1, argv[2]);
	free(buf1);

	index = find_index_lists(*head, argv[1]);
	if (index == 0)
	{
		add_node_ends(head, buf2);
		free(buf2);
		return (0);
	}

	if (index > 0)
	{
		delete_node_at_indexs(head, index);
		add_node_at_indexs(head, buf2, index);
		free(buf2);
		return (0);
	}

	free(buf2);
	return (0);
}

/**
 * _unsetenv - unsets an environment
 * @head: double pointer
 * @argv: array of strings
 *
 * Description: If no arguments
 *
 * Return: 0 on success, -1 on failure
 */
int _unsetenv(env_t **head, char **argv)
{
	int index;

	if (!argv[1])
		return (-1);

	index = find_index_lists(*head, argv[1]);
	if (index == 0 || !head || !*head)
		return (0);

	else
		delete_node_at_indexs(head, index);

	return (0);
}

/**
 * setenv_handlers - handles the s
 * @argv: array of arguments
 * @head: pointer to
 * @j: index of
 * @prog_name: n
 *
 * Description: Count the umber
 */
void setenv_handlers(char **argv, env_t **head, int *j, char *prog_name)
{
	int n = 0, m = 0, args = 0;
	char *unset_err = "unsetenv: Too few arguments.\n";

	while (argv[args])
		args++;

	if (!_strcmp(argv[0], "setenv"))
	{
		n = _setenv(head, argv, args);
		if (n == -1)
			print_error_setenvs(j, prog_name, argv);
	} else if (!_strcmp(argv[0], "unsetenv"))
	{
		m = _unsetenv(head, argv);
		if (m == -1)
			write(2, unset_err, _strlen(unset_err));
	}
}

/**
 * print_error_setenvs - prints a custom error message
 * @j: index of the command
 * @s: name of the p
 * @argv: array of arguments
 *
 * Description: Concatenate strings
 */
void print_error_setenvs(int *j, char *s, char **argv)
{
	char *buf1 = NULL, *buf2 = NULL, *buf3 = NULL, *buf4 = NULL, *buf5 = NULL;
	char *number = NULL;

	number = convert(*j, 10);

	buf1 = str_concat(s, ": ");
	buf2 = str_concat(buf1, number);
	free(buf1);
	buf3 = str_concat(buf2, ": ");
	free(buf2);
	buf4 = str_concat(buf3, argv[0]);
	free(buf3);
	buf5 = str_concat(buf4, ": Bad ble ame\n");
	free(buf4);
	write(2, buf5, _strlen(buf5));
	free(buf5);
}
