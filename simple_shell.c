#include "simple_shell.h"

extern char **environ;

void display_prompt(void)
{
	write(STDOUT_FILENO, "$ ", 2);
}

char *read_user_command(void)
{
	char *line = NULL; //*buffer where line will be stock
	size_t len = 0; //*size of buffer
	ssize_t read; //* number of charactere read

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
