#include "main.h"
/**
 * execute - Forks and executes a command with its arguments.
 * @args: NULL-terminated array of strings (command + arguments).
 *
 * Return: The exit status of the command (127 if not found).
 */
int execute(char **args)
{
	pid_t	pid;
	int	status;
	char	*cmd_path;

	if (handle_builtin(args))
		return (0);
	if (strchr(args[0], '/') != NULL)
		cmd_path = strdup(args[0]);
	else
		cmd_path = get_path(args[0]);
	if (cmd_path == NULL)
	{
		fprintf(stderr, "%s: 1: %s: not found\n", program_name, args[0]);
		return (127);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		free(cmd_path);
		return (1);
	}
	if (pid == 0)
	{
		if (execve(cmd_path, args, environ) == -1)
		{
			fprintf(stderr, "%s: 1: %s: not found\n",
				program_name, args[0]);
			free(cmd_path);
			_exit(127);
		}
	}
		waitpid(pid, &status, 0);
		free(cmd_path);
		if (WIFEXITED(status))
			return (WEXITSTATUS(status));
	return (0);
}
