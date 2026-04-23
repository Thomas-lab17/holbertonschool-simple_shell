#include "main.h"

/**
 * get_path_value - Gets the value of the PATH environment variable.
 *
 * Return: A pointer to the PATH value, or NULL if not found.
 */
char *get_path_value(void)
{
	int	i = 0;

	if (environ == NULL)
		return (NULL);
	while (environ[i])
	{
		if (strncmp(environ[i], "PATH=", 5) == 0)
			return (environ[i] + 5);
		i++;
	}
	return (NULL);
}

/**
 * get_path - Finds the full path of a command by searching PATH.
 * @command: the command name to search for
 *
 * Return: The full path string if found, or NULL if not found.
 */
char *get_path(const char *command)
{
	char *path_env, *path_copy, *dir, *full_path;
	struct stat	st;

	path_env = get_path_value();
	if (!path_env)
		return (NULL);
	path_copy = strdup(path_env);
	if (!path_copy)
		return (NULL);
	dir = strtok(path_copy, ":");
	while (dir != NULL)
	{
		full_path = malloc(strlen(dir) + strlen(command) + 2);
		if (!full_path)
		{
			free(path_copy);
			return (NULL);
		}
		sprintf(full_path, "%s/%s", dir, command);
		if (stat(full_path, &st) == 0)
		{
			free(path_copy);
			return (full_path);
		}
		free(full_path);
		dir = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}
