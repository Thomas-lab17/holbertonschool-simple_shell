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
			args = tokenize(input);
			if (args != NULL)
			{
				execute(args);
				free(args);
			}
		}
		free(input);
	}
	return (0);
}

