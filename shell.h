#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/stat.h>
#include <signal.h>

int lens(char *word);
void my_print(char *word);
int comp_str(char *first, char *second);

void execute_command(char *command, char **args);

#endif
