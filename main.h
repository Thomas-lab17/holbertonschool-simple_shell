#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>	
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

extern char **environ;
void display_prompt(void);
char *read_input(void);
char *get_path_value(void);
char *get_path(const char *command);
void execute(char *command);


#endif