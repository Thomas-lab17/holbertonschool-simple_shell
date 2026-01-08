#include "simple_shell.h"

char *find_command_in_path(char *command)
{
	char *path_env, *path_copy, *dir, *full_path;
	int i;

	if (strchr(command, '/'))
	{
		if (check_command(command))
			return (strdup(command));
		return (NULL);
	}

	for (i = 0; environ[i]; i++)
	{
		if (strncmp(environ[i], "PATH=", 5) == 0)
		{
			path_env = environ[i] + 5;
			break;
		}
	}

	if (!path_env)
		return (NULL);

	path_copy = strdup(path_env);
	dir = strtok(path_copy, ":");

	while (dir)
	{
		full_path = malloc(strlen(dir) + strlen(command) + 2);
		if (!full_path)
			break;

		sprintf(full_path, "%s/%s", dir, command);

		if (check_command(full_path))
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