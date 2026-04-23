#include "main.h"

/**
 * strip_whitespace - Removes leading and trailing whitespace from a string.
 * @str: the string to modify in place
 *
 * Return: void
 */
void strip_whitespace(char *str)
{
	int	start = 0;
	int	len;

	while (str[start] == ' ' || str[start] == '\t')
		start++;
	if (start > 0)
	{
		len = 0;
		while (str[start + len] != '\0')
		{
			str[len] = str[start + len];
			len++;
		}
		str[len] = '\0';
	}
	len = strlen(str) - 1;
	while (len >= 0 && (str[len] == '\n' || str[len] == ' '
		|| str[len] == '\t'))
	{
		str[len] = '\0';
		len--;
	}
}
