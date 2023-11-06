#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>


void display_prompt(void);
void kevdan_print(const char *format);
void read_command(char *command, size_t size);
void execute_command(const char *command);


#endif 
