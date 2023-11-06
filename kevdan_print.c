#include "shell.h"

/**
 * kevdan_print - creates the printf for this project
 *
 * Format - gives the format
 */
void kevdan_print(const char *format)
{
	write(STDOUT_FILENO, format, strlen(format));
}

