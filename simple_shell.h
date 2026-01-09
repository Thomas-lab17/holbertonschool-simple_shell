#ifndef SIMP_H
#define SIMP_H


#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/stat.h>

char *read_command(void);
void execute_command(char *path, char **argv);
int check_command(char *path);
void display_prompt(void);
char *find_command_in_path(char *command);
char *read_user_command(void);
extern char **environ;


#endif
