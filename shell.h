#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_COMMAND_LENGTH 256
void displayPrompt(void);
void handleCommandExecution(const char *command);

#endif /* SIMPLE_SHELL_H*/

