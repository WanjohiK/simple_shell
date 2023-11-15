#include "shell.h"

/**
 * displayPrompt - Display the shell prompt.
 */
void displayPrompt(void)
{
	write(STDOUT_FILENO, "simple_shell$ ", 13);
}

/**
 * handleCommandExecution - Execute a shell command.
 * @command: The command to execute.
 */
void handleCommandExecution(const char *command)

{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("Fork failed");
		exit(1);
	}
	else if (pid == 0)
	{
		if (execlp(command, command, NULL) == -1)
		{
			perror("Command execution failed");
			exit(1);
		}
	}
	else
	{
		int status;

		waitpid(pid, &status, 0);
		if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
		{
			write(STDOUT_FILENO, "Command execution failed\n", 25);
		}
	}
}


