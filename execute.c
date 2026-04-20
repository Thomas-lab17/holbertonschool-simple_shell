#include "main.h"
/**
 * execute_command - Executes a command using execve.
 *
 * @command: The command to execute (e.g., "ls").
 *
 * Return: 0 on success, or -1 on failure.
 */

void execute(char *command)
{
    pid_t pid;
    int status;

    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        return;
    }

    if (pid == 0)
    {
        if (execve(command, argv, environ) == -1)
        {
            fprintf(stderr, "./hsh: 1: %s: not found\n", command);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        waitpid(pid, &status, 0);
    }
}