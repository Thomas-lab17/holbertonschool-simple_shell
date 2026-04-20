#include "main.h"

/**
 * tokenize - Splits an input string into an array of tokens.
 * @input: the raw input string
 * Return: a NULL-terminated array of strings, or NULL on failure.
 */
char **tokenize(char *input)
{
	char **args;
	char *token;
	int i = 0;

	args = malloc(sizeof(char *) * 64);
	if (!args)
		return (NULL);
	token = strtok(input, " \t\n");
	while (token != NULL)
	{
		args[i++] = token;
		token = strtok(NULL, " \t\n");
	}
	args[i] = NULL;
	return (args);
}