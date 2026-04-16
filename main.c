#include "main.h"

int main(void)
{
	char *input;

	display_prompt();
	input = read_input();
	if (input != NULL)
	{
		printf("%s", input);
		free(input);
	}
	return (0);
}
