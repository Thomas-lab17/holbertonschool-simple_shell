#include "main.h"
/**
*
*
*
*
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