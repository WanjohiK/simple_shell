#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "shell.h"

/**
 * main - Entry point of the simple shell program.
 * Return: (0) Always.
 */
int main(void)
{
	char command[MAX_COMMAND_LENGTH];

	while (1)
	{
		displayPrompt();
		if (!fgets(command, sizeof(command), stdin))
		{
			write(STDOUT_FILENO, "\n", 1);
			break;
		}

		command[strlen(command) - 1] = '\0';
		handleCommandExecution(command);
	}

	return (0);
}

