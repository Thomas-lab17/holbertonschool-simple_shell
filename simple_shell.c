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

int check_command(char *command)
{
	struct stat st;

	if (stat(command, &st) == -1)
		return (0);

	if (!(st.st_mode & S_IXUSR || S_IXGRP || S_IXOTH))
		return (0);

	return (1);
}
void execute_command(char *command)
{
	pid_t pid;
	char *argv[2];
	argv[0] = command;
	argv[1] = NULL;
	pid = fork();

	if (pid == -1)
	{
		perror("fork");
		return;
	}

	if (pid == 0)
	{
		if (execve(command, argv, environ) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(NULL);
	}
}
int main(void)
{
	char *command;

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

		if (!check_command(command))
		{
			write(STDERR_FILENO, "Command not found\n", 18);
			free(command);
			continue;
		}

		execute_command(command);
		free(command);
	}

	return (0);
}