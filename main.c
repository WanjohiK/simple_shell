#include "shell.h"

/**
* execs - handles commands
* @input: array ofstandard input
* @n: name of 
* @j: index of error
* @head: linked containing environment
*
* Description: making child process
*
* Return: return with 1 on success,  0 failure
*/
int execs(char **input, char *n, int *j, env_t **head)
{
	struct stat filestat;
	int status = 0;
	char *exe = NULL, **env = NULL;
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		print_errors(j, n, input);
		free_everything(input);
		exit(EXIT_SUCCESS);
	}
	if (child_pid == 0)
	{
		env = list_to_arr(*head);
		if (get_env_vals("PATH=", env)[0] != '/')
			execve(input[0], input, env);
		exe = path_finders(input, env);
		if (!exe && !stat(input[0], &filestat))
		{
			if (execve(input[0], input, env) == -1)
			{
				print_errors(j, n, input);
				free_everything(input), free_everything(env);
				return (0);
			}
			free_everything(input);
			free_everything(env);
		}
		if (execve(exe, input, env) == -1)
		{
			print_errors(j, n, input);
			free(exe), free_everything(input), free_everything(env);
			exit(EXIT_SUCCESS);
		}
	}
	else
		wait(&status);
	free_everything(input), free_everything(env);
	return (1);
}

/**
 * main - simple command-line argument 
 * prints a prompt and waits
 * @ac: number of ar
 * @av: array of arg
 *
 * Description: If an argument 
 *
 * Return: always 0, for success
 */
int main(int ac, char *av[])
{
	size_t len = 0;
	int cmd_count = 0, get;
	char **input = NULL, *line = NULL, *prog_name = av[0];
	env_t *head = NULL;

	if (ac != 1)
	{
		print_error_main(av);
		exit(127);
	}
	signal(SIGINT, sigint_handler);
	arr_to_list(&head, environ);
	while (1)
	{
		if (isatty(STDIN_FILENO) != 0 && isatty(STDOUT_FILENO) != 0)
			print_prompt();
		get = getline(&line, &len, stdin);
		if (get < 0)
		{
			if (isatty(STDIN_FILENO) != 0 && isatty(STDOUT_FILENO) != 0)
				_putchar('\n');
			break;
		}
		cmd_count++;
		if (_strcmp(line, "\n") == 0)
			continue;
		input = parse_line(line, get);
		if (!input)
			continue;
		if (is_builtins(line, input, prog_name, &cmd_count, &head))
		{
			free_everything(input);
			continue;
		}
		if (!execs(input, prog_name, &cmd_count, &head))
			break;
	}
	free_list(&head), free(line);
	return (0);
}
