#include "main.h"

extern char **environ;

/**
 * execute - Forks and executes a command with its arguments.
 * @args: NULL-terminated array of strings (command + arguments).
 * Return: void
 */
void execute(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return;
	}
	if (pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
			fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
			_exit(127);
		}
	}
	else
		waitpid(pid, &status, 0);
}