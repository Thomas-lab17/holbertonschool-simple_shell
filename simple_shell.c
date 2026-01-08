
#include "simple_shell.h"

extern char **environ;

int main(void)
{
	char *command;
	char *path;

	while (1)
{
	char **argv = NULL;
	size_t argc = 0, cap = 8;
	char *token;

	display_prompt();

	command = read_user_command();
	if (command == NULL)
	{
		write(STDOUT_FILENO, "\n", 1);
		break;
	}

	argv = malloc(sizeof(char *) * cap);
	if (!argv)
	{
		free(command);
		continue;
	}

	token = strtok(command, " \t");
	while (token)
	{
		if (argc + 1 >= cap)
		{
			char **tmp;
			cap *= 2;
			tmp = realloc(argv, sizeof(char *) * cap);
			if (!tmp)
			{
				free(argv);
				free(command);
				argv = NULL;
				break;
			}
			argv = tmp;
		}

		argv[argc++] = token;
		token = strtok(NULL, " \t");
	}

	if (!argv)
		continue;

	argv[argc] = NULL;

	if (argc == 0)
	{
		free(argv);
		free(command);
		continue;
	}
	path = find_command_in_path(argv[0]);
	if (!path)
	{
		write(STDERR_FILENO, "Command not found\n", 18);
		free(argv);
		free(command);
		continue;
	}

	execute_command(path, argv);

	free(path);
	free(argv);
	free(command);
}

	return (0);
}
