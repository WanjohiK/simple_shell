#include "shell.h"

/**
 * main - contains the main function
 *
 * Return: success 0
 */

int main(void)
{
	char command[114];

	while (1)
	{
		display_prompt();
		read_command(command, sizeof(command));
		execute_command(command);
	}

	return (0);
}
