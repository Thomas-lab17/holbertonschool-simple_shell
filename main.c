#include "main.h"
/**
 * main - entry point of the shell program
 *
 * Return: 0 on success, or a non-zero value on failure
 */

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

        input[strcspn(input, "\n")] = '\0';

        if (input[0] != '\0')
            execute(input);

        free(input);
    }
    return (0);
}

