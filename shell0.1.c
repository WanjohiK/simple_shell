#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024

/**
 * display_prompt - Display the shell prompt
 */
void display_prompt(void)
{
	printf("$");
	fflush(stdout);
}

/**
 * execute_command - Execute the given command
 * @command: The command to be executed
 * Return: 1 on success, 0 on failure
 */
int execute_command(char *command)
{
	pid_t pid, wpid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		/* Child process */
		if (execve(command, NULL, environ) == -1)
		{
			perror("Error");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		/* Forking error */
		perror("Error");
	}
	else
	{
		/* Parent process */
		do {
			wpid = waitpid(pid, &status, WUNTRACED);
		} while (!(WIFEXITED(status)) && !(WIFSIGNALED(status)));
	}

	return (1);
}

/**
 * main - The main function for the simple shell
 * Return: Always 0
 */
int main(void)
{
	char input[MAX_INPUT_SIZE];

	while (1)
	{
		display_prompt();

		/* Read command from user */
		if (fgets(input, MAX_INPUT_SIZE, stdin) == NULL)
		{
			/* Handle end of file (Ctrl+D) */
			printf("\n");
			break;
		}

		/* Remove newline character at the end */
		input[strcspn(input, "\n")] = '\0';

		/* Execute command */
		if (strlen(input) > 0)
		{
			if (execute_command(input) == 0)
			{
				break; /* Exit if there's an error */
			}
		}
	}

	return (0);
}

