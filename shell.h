#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>

#include <limits.h>
#include <sys/types.h>


extern char **environ;

/**

 * struct list_s - singly linked list
 * @str: string - (malloc'ed string)
 * @next: points to the next node
 *
 * Description: singly linked list node structure

 * struct list_s - shows singly linked list
 * @str: string - (malloc'ed string)
 * @next: pointer
 *
 * Description: singly

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
=======

int execu(char **input, char *s, int *i, env_t **head);
int main(int ac, char *av[]);

/* path_finder.c */
char **get_envs(char *name, char **env);
char *path_finders(char **s, char **env);
char *get_env_vals(char *name, char **env);

/* tokenize.c */
int wordcounts(char *str, char delim);
char **_strtoks(char *str, char delim);

/* print_funcs.c */
void print_prompt(void);
int _putchar(char c);
void _puts(char *str);

/* print_errors.c */
void print_errors(int *j, char *n, char **argv);
void print_error_envs(char **argv);
void print_error_exits(int *j, char *n, char **argv);
void print_error_main(char **av);
void print_error_cd(int *j, char *n, char **argv);

/* string_funcs_1.c */
int _strcmp(char *s1, char *s2);
char *str_concat(char *s1, char *s2);
char *_strstr(char *haystack, char *needle);
int _strncmp(char *s1, char *s2, unsigned int n);
char *_strdup(char *str);

/* string_funcs_2.c */
int _strlen(char *s);
char *_strcpy(char *dest, char *src);

/* helper_funcs.c */
void free_everything(char **args);
void sigint_handler(int sig);
char **parse_line(char *line, int get);

/* builtins.c */
int is_builtins(char *line, char **argv, char *prog_name, int *i, env_t **head);

long int exit_handlers(char **tokens);
int env_handlers(char **av, env_t **head);
int cd_handlers(char **argv, env_t **head);
void change_pwds(char *path, char **env, env_t **head);


/*main.c*/
int execs(char **input, char *n, int *j, env_t **head);
int main(int ac, char *av[]);

/* convert.c */
char *convert(int num, int base);
long int _atoi(char *s);

/* list_funcs_1.c */
env_t *add_node_end(env_t **head, char *str);
int add_node_at_index(env_t **head, char *str, int index);
int delete_node_at_index(env_t **head, unsigned int index);
int find_index_list(env_t *head, char *name);

/* list_funcs_2.c */
size_t list_len(const env_t *h);
size_t print_list(env_t *h);
void free_list(env_t **head);
int arr_to_list(env_t **head, char **env);
char **list_to_arr(env_t *head);

/* set_env.c */
int _unsetenv(env_t **head, char **argv);
int _setenv(env_t **head, char **argv, int args);
void setenv_handler(char **argv, env_t **head, int *i, char *prog_name);
void print_error_setenv(int *i, char *s, char **argv);


#endif
