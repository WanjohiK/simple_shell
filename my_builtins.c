#include "shell.h"

/**
 * is_builtins - checks if the command is a builtin
 * @line: line from input, passed in to free properly
 * @prog_name: name of the program
 * @argv: parsed command line
 * @j: pointer to the increment variable of main
 * @head: double pointer to the environ linked list
 *
 * Description: Intermediate step
 *
 * Return: 0 to main
 */
int is_builtins(char *line, char **argv, char *prog_name, int *j, env_t **head)
{
	int k, r;
	long int p;

	if (!_strcmp(argv[0], "exit"))
	{
		p = exit_handlers(argv);
		if (p == -1)
			print_error_exits(j, prog_name, argv);
		else
		{
			free_everything(argv);
			free(line);
			free_list(head);
			exit(p);
		}
		return (1);
	}
	if (!_strcmp(argv[0], "env"))
	{
		k = env_handlers(argv, head);
		if (k == -1)
			print_error_envs(argv);
		return (1);
	}
	if (!_strcmp(argv[0], "setenv") || !_strcmp(argv[0], "unsetenv"))
	{
		setenv_handler(argv, head, j, prog_name);
		return (1);
	}
	if (!_strcmp(argv[0], "cd"))
	{
		r = cd_handlers(argv, head);
		if (r == -1)
		{
			print_error_cd(j, prog_name, argv);
			write(2, "\n", 1);
		}
		return (1);
	}
	return (0);
}

/**
 * exit_handlers - handles builtin exit
 * @tokens: array of strings
 *
 * Description: no second token,
 *
 * Return: 0 if there are no arguments -1 error
 */
long int exit_handlers(char **tokens)
{
	int flag = 0, j;
	long int num = 0;

	if (tokens[1] == NULL)
		return (num);
	for (j = 0; tokens[1][j]; j++)
	{
		if ((tokens[1][j] >= '0' && tokens[1][j] <= '9') || tokens[1][0] == '+')
		{
			flag = 1;
			if (tokens[1][j + 1] < '0' || tokens[1][j + 1] > '9')
				break;
		}
		else
			break;
		flag = 0;
	}
	if (flag == 1)
	{
		num = _atoi(tokens[1]);
		return (num);
	}
	return (-1);
}

/**
 * env_handlers - replicate
 * @av: array of arguments
 * @head: double pointer
 *
 * Return: 0 on success, -1 on error
 */
int env_handlers(char **av, env_t **head)
{
	if (av[1] == NULL)
	{
		print_list(*head);
		return (0);
	}
	return (-1);
}

/**
 * cd_handlers - replicates the
 * @argv: array of arguments
 * @head: double pointer
 *
 * Description: Transform linked list
 *
 * Return: 0 if none of the other cases succeeded
 */
int cd_handlers(char **argv, env_t **head)
{
	char *home = NULL, *old = NULL, **env = NULL;

	env = list_to_arr(*head);
	if (!argv[1])
	{
		home = get_env_vals("HOME=", env);
		chdir(home);
		change_pwds(home, env, head);
		free_everything(env);
		return (1);
	}
	if (_strcmp(argv[1], "-") == 0)
	{
		old = get_env_vals("OLDPWD=", env);
		_puts(old);
		change_pwds(old, env, head);
		chdir(old);
		free_everything(env);
		return (1);
	}
	if (chdir(argv[1]) < 0)
	{
		free_everything(env);
		return (-1);
	}
	else
	{
		change_pwds(argv[1], env, head);
		free_everything(env);
		return (1);
	}
	return (0);
}

/**
 * change_pwds - helper function for cd
 * @path: path of the working directories
 * @head: double pointer
 * @env: double array
 *
 * Description: Allocate new array
 */
void change_pwds(char *path, char **env, env_t **head)
{
	char **old = NULL, **current = NULL;
	int nodes = 0, set = 0;

	old = malloc(sizeof(char *) * 4);
	old[0] = _strdup("old");
	old[1] = _strdup("OLDPWD");
	old[2] = _strdup(get_env_vals("PWD=", env));
	old[3] = NULL;
	current = malloc(sizeof(char *) * 4);
	current[0] = _strdup("current");
	current[1] = _strdup("PWD");
	current[2] = _strdup(path);
	current[3] = NULL;
	nodes = arr_to_list(head, env);
	if (!nodes)
		return;
	set = _setenv(head, old, 2);
	if (set < 0)
	{
		free_everything(old);
		free_everything(current);
		return;
	}
	free_everything(old);
	set = _setenv(head, current, 2);
	if (set < 0)
	{
		free_everything(current);
		return;
	}
	free_everything(current);
}
