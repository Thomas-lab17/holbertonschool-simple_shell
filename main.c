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

if (input != NULL)
{
printf("%s", input);
free(input);
}
else
{
break;
}
}
return (0);
}

