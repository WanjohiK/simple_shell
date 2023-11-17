#include "shell.h"

/**
* exec - execution of commands
* @input: array of arguments from stdi
* @s: name of the program
* @j: index of error
* @head: linked list containing env
*
* Description: make child processss
*
* Return: return to main looping with 1 on success, or 0 on failure
*/
int exec(char **input, char *s, int *j, env_t **head)
{
	struct stat filestat;
	int status = 0;
	char *exe = NULL, **env = NULL;
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		print_errors(j, s, input);
		free_everything(input);
		exit(EXIT_SUCCESS);
	}
	if (child_pid == 0)
	{
		env = list_to_arrs(*head);
		if (get_env_vals("PATH=", env)[0] != '/')
			execve(input[0], input, env);
		exe = path_finders(input, env);
		if (!exe && !stat(input[0], &filestat))
		{
			if (execve(input[0], input, env) == -1)
			{
				print_errors(j, s, input);
				free_everything(input), free_everything(env);
				return (0);
			}
			free_everything(input);
			free_everything(env);
		}
		if (execve(exe, input, env) == -1)
		{
			print_errors(j, s, input);
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
 * main - simple command-line argument interpreter
 * prints a prompt and waits 
 * @ac: number of arguments
 * @av: array of arguments
 *
 * Description: If an arg is passed to main, print error, exit
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
		print_error_mains(av);
		exit(127);
	}
	signal(SIGINT, sigint_handlers);
	arr_to_lists(&head, environ);
	while (1)
	{
		if (isatty(STDIN_FILENO) != 0 && isatty(STDOUT_FILENO) != 0)
			print_prompts();
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
		input = parse_lines(line, get);
		if (!input)
			continue;
		if (is_builtins(line, input, prog_name, &cmd_count, &head))
		{
			free_everything(input);
			continue;
		}
		if (!exec(input, prog_name, &cmd_count, &head))
			break;
	}
	free_lists(&head), free(line);
	return (0);
}
