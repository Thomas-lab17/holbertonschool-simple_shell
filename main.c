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
			args = tokenize(input); //if the command entered was exit,
			if (args != NULL) //frees up the args and input and closes the program
			{
				if (strcmp(args[0], "exit") == 0) //should exit gracefully?
				{
					free(args);
					free(input);
					break;
				}
				execute(args);
				free(args);
			}
		}
		free(input); //exits 
	}
	return (0);
}
