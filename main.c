#include "main.h"

/**
 * main - Entry point of the shell program.
 *
 * Return: 0 on success, non-zero on failure.
 */
int main(void)
{
	char *input;
	char **args;
	int j;

	while (1)
	{
		display_prompt();
		input = read_input();
		if (input == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			break;
		}
		strip_whitespace(input);
		if (input[0] != '\0')
		{
			args = tokenize(input);
			if (args != NULL)
			{
				execute(args);
				for (j = 0; args[j] != NULL; j++)
					free(args[j]);
				free(args);
			}
		}
		free(input);
	}
	return (0);
}

