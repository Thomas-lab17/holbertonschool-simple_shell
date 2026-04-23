#include "main.h"

int main(void)
{
	char *input;

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
		if (strcmp(input, "exit\n") == 0 || strcmp(input, "exit") == 0) //should exit gracefully?
		{
			free(input);
			break;
		}
		printf("%s", input);
		free(input); //exits 
	}
	return (0);
}
