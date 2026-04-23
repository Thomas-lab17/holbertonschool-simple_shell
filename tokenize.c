#include "main.h"
#include <string.h>

/**
 * tokenize - Splits an input string into an array of tokens.
 * @input: the raw input string
 *
 * Return: A NULL-terminated array of strings, or NULL on failure.
 */
char **tokenize(char *input)
{
	char	**args;
	char	*input_copy;  /* ✅ NOUVEAU */
	char	*token;
	int	i = 0;

	args = malloc(sizeof(char *) * 64);
	if (!args)
		return (NULL);

	/* ✅ NOUVEAU : Copier input pour ne pas le modifier */
	input_copy = strdup(input);
	if (!input_copy)
	{
		free(args);
		return (NULL);
	}

	token = strtok(input_copy, " \t\n");
	while (token != NULL)
	{
		/* ✅ NOUVEAU : Copier le token au lieu de stocker le pointeur */
		args[i] = malloc(strlen(token) + 1);
		if (!args[i])
		{
			free(input_copy);
			free(args);
			return (NULL);
		}
		strcpy(args[i], token);
		i++;
		token = strtok(NULL, " \t\n");
	}
	args[i] = NULL;
	free(input_copy);  /* ✅ NOUVEAU : Libérer la copie */
	return (args);
}
