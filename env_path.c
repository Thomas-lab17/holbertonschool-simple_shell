#include "main.h"

/**
 * handle_builtin - handles built-in commands.
 * @args: tokenized command line
 *
 * Return: 1 if a built-in was executed, 0 otherwise.
 */
int handle_builtin(char **args)
{
	int i;

	if (args == NULL || args[0] == NULL)
		return (0);
	if (strcmp(args[0], "env") != 0)
		return (0);
	i = 0;
	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
	return (1);
}
