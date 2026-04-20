#include "main.h"
/**
 * read_input - Reads a line of input from the user.
 *
 * Return: A pointer to the input string.
 */
char *read_input(void)
{
	char *input;
  size_t len = 0;

  getline (&input, &len, stdin);
  return (input);
  printf("%s", input);
  free(input);

}