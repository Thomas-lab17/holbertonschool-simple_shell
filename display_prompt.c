#include "main.h"

/**
 * display_prompt - Displays the shell prompt in interactive mode.
 *
 * Return: void
 */
void display_prompt(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
}
