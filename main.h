#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>	
#include <unistd.h>

void display_prompt(void);
char *read_input(void);
char *get_path(char *command);


#endif