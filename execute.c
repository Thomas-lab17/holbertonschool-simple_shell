#include "main.h"

/**
 * execute - Forks and executes a command with its arguments.
 * @args: NULL-terminated array of strings (command + arguments).
 *
 * Return: void
 */
void execute(char **args)
{
	pid_t pid;
	int	status;
	char *cmd_path;

	if (strchr(args[0], '/') != NULL)
		cmd_path = strdup(args[0]);
	else
		cmd_path = get_path(args[0]);
	if (cmd_path == NULL)
	{
		fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
		return;
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		free(cmd_path);
		return;
	}
	if (pid == 0)
	{
		if (execve(cmd_path, args, environ) == -1)
		{
			fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
			free(cmd_path);
			_exit(127);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
		free(cmd_path);
	}
}