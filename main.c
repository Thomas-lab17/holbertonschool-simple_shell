#include "main.h"


void trim(char *str)
{
    int start = 0;
    int len;

    /* Strip leading whitespace */
    while (str[start] == ' ' || str[start] == '\t')
        start++;

    /* Shift string left if needed */
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

    /* Strip trailing whitespace */
    len = strlen(str) - 1;
    while (len >= 0 && (str[len] == '\n' || str[len] == ' ' || str[len] == '\t'))
    {
        str[len] = '\0';
        len--;
    }
}
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

        trim(input);

        if (input[0] != '\0')
            execute(input);

        free(input);
    }
    return (0);
}

