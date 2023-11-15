#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>
#include <limits.h>

extern char **environ;

/**
 * struct list_s - singly linked list
 * @str: string - (malloc'ed string)
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 */
typedef struct list_s
{
	char *str;
	struct list_s *next;
} env_t;

/* AuxFunctions.c */
void handle_sigint(int sig);
void release_all(char **args);
char **handle_line(char *line, int size);

/* Convert.c */
long int _strToNum(char *str);
char *_numToStrBase(int num, int base);

/* environ.c */
int customSetenv(env_t **head, char **argv, int args);
int customUnsetenv(env_t **head, char **argv);
void setenvHandler(char **argv, env_t **head, int *i, char *progName);
void printErrorSetenv(int *i, char *s, char **argv);

/* listFunctions.c */
env_t *add_node_end(env_t **head, char *str);
int delete_node_at_index(env_t **head, unsigned int index);
int add_node_at_index(env_t **head, char *str, int idx);
int find_index_list(env_t *head, char *name);

/*listFunctions2.c*/
int convert_arr_to_list(env_t **head, char **env_array);
char **convert_list_to_arr(env_t *head);
size_t display_list(env_t *node);
void eliminate_list(env_t **head);
size_t determine_list_length(const env_t *node);

/*printErr*/
void printError(int *i, char *s, char **argv);
void printErrorEnv(char **argv);
void printErrorExit(int *i, char *s, char **argv);
void printErrorMain(char **av);
void printErrorCd(int *i, char *s, char **argv);

/*printFunctions*/
int customPutchar(char c);
void printPrompt(void);
void customPuts(char *str);

/*strFunc1*/
char *customStrdup(char *str);
char *customStrConcat(char *s1, char *s2);
int customStrCmp(char *s1, char *s2);
int customStrNcmp(char *s1, char *s2, unsigned int n);

/*strFunc2*/
int customStrlen(char *s);
char *customStrcpy(char *dest, char *src);

/*my_tokenize.c*/
int wordcounts(char *str, char delim);
char **_strtoks(char *str, char delim);

/*my_path_finder.c*/
char *get_env_vals(char *name, char **env);
char **get_envs(char *name, char **env);
char *path_finders(char **n, char **env);

/*my_builtins.c*/
int is_builtins(char *line, char **argv, char *prog_name, int *j, env_t **head);
long int exit_handlers(char **tokens);
int env_handlers(char **av, env_t **head);
int cd_handlers(char **argv, env_t **head);
void change_pwds(char *path, char **env, env_t **head);

/*main.c*/
int execs(char **input, char *n, int *j, env_t **head);
int main(int ac, char *av[]);

#endif
