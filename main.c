#include "main.h"

<<<<<<< HEAD
char *program_name = NULL;

/**
 * main - Entry point of the shell program.
 * @argc: argument count (unused)
 * @argv: argument vector; argv[0] is used as the program name in errors
 *
 * Return: The exit status of the last command executed.
 */
int main(int argc, char **argv)
{
	char	*input;
	char	**args;
	int	status = 0;
=======
int main(void)
{
char *program_name = NULL;

/**
 * main - Entry point of the shell program.
 * @argc: argument count (unused)
 * @argv: argument vector; argv[0] is used as the program name in errors
 *
 * Return: The exit status of the last command executed.
 */
int main(int argc, char **argv)
{
	char	*input;
	char	**args;
	int	status = 0;

	(void)argc;
	program_name = argv[0];
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
				if (strcmp(args[0], "exit") == 0) //should exit gracefully?
				{
					free(args);
					free(input);
					break;
				}
				status = execute(args);
				free(args);
			}
		}
		free(input); //exits 
	}
	return (status);
}
