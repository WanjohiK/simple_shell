#include "shell.h"

/**
* get_env_vals - gets the
* @name: env key
* @env: array of strings
*
* Description: loop through strings
*
* Return: value of name in env
*/

char *get_env_vals(char *name, char **env)
{
	int j;

	for (j = 0; env[j]; j++)
		if (_strncmp(env[j], name, _strlen(name)) == 0)
			return (env[j] + _strlen(name));
	return (NULL);
}

/**
* get_envs - transform the PATH
* @name: key (key=value) to select in env
* @env: array of strings
*
* Description: loop  strings in env
* Return: value at key
*/
char **get_envs(char *name, char **env)
{
	char **value = NULL, **path = NULL;
	int j;

	for (j = 0; env[j]; j++)
	{
		path = _strtoks(env[j], '=');
		if (_strcmp(name, path[0]) == 0)
		{
			value = _strtoks(path[1], ':');
			free_everything(path);
			return (value);
		}
		else
			free_everything(path);
	}
	free_everything(path);
	free_everything(value);
	return (NULL);
}
/**
* path_finders - connect directories
* @n: input, in form
* @env: array of strings
*
* Description: call get_env
*
* Return: concatenated string on success otherwise failurial
*/
char *path_finders(char **n, char **env)
{
	int j;
	char *dir = NULL;
	char *prog = NULL;
	char **path_value = NULL;

	path_value = get_envs("PATH", env);
	if (!path_value)
	{
		free_everything(path_value);
		return (NULL);
	}

	for (j = 0; path_value[j]; j++)
	{
		dir = str_concat(path_value[j], "/");
		prog = str_concat(dir, n[0]);

		if (access(prog, X_OK) == 0)
		{
			free_everything(path_value);
			free(dir);
			return (prog);
		}
		free(dir);
		free(prog);
	}
	free_everything(path_value);
	return (NULL);
}
