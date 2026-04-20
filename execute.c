#include "main.h"

extern char **environ;

/**
 * execute - Executes a command using execve.
 * @command: The command to execute (e.g., "/bin/ls").
 * Return: void
 */
void execute(char *command)
{
    pid_t pid;
    int status;
    char *argv[2];

    argv[0] = command;
    argv[1] = NULL;

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
            /* Print actual errno to stderr for debugging */
            fprintf(stderr, "DEBUG execve failed: cmd=[%s] errno=%d: %s\n",
                    command, errno, strerror(errno));
            _exit(EXIT_FAILURE);
        }
    }
    else
    {
        waitpid(pid, &status, 0);
    }
}