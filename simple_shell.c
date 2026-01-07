#define _POSIX_C_SOURCE 200809L
#include "simple_shell.h"

extern char **environ;

void display_prompt(void)
{
	write(STDOUT_FILENO, "$ ", 2);
}

char *read_user_command(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	read = getline(&line, &len, stdin);

	if(read == -1)
	{
		free(line);
		return (NULL);
	}

	if (line[read - 1] == '\n')
		line[read - 1] = '\0';

	return(line);
}

int check_command(char *path)
{
	struct stat st;

	if (stat(path, &st) == -1)
		return (0);

	if (!(st.st_mode & (S_IXUSR || S_IXGRP || S_IXOTH)))
		return (0);

	return (1);
}

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

void execute_command(char *path)
{
	pid_t pid;
	char *argv[2];
	argv[0] = path;
	argv[1] = NULL;
	pid = fork();

	if (pid == -1)
	{
		perror("fork");
		return;
	}

	if (pid == 0)
	{
		execve(path, argv, environ);
		perror("execve");
		exit(EXIT_FAILURE);
	}

	else
	{
		wait(NULL);
	}
}
int main(void)
{
	char *command;
	char *path;

	while (1)
	{
		display_prompt();

		command = read_user_command();
		if (command == NULL)
		{
			write(STDOUT_FILENO, "\n", 1);
			break;
		}

		if (strlen(command) == 0)
		{
			free(command);
			continue;
		}

		path = find_command_in_path(command);
		if (!path)

		{
			write(STDERR_FILENO, "Command not found\n", 18);
			free(command);
			continue;
		}

		execute_command(path);

		free(path);
		free(command);
	}

	return (0);
}
