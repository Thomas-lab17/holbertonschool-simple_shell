#include "main.h"

/**
 * read_input - Reads a line of input from stdin.
 *
 * Return: A pointer to the input string, or NULL on failure or EOF.
 */
char *read_input(void)
{
	char	*line = NULL;
	size_t	bufsize = 0;
	ssize_t	nread;

	nread = getline(&line, &bufsize, stdin);
	if (nread == -1)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
