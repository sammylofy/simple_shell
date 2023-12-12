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

#define MAX_INPUT_SIZE 1024
#define MAX_ARGS 100

int lens(char *word);
void my_print(char *word);
int comp_str(char *first, char *second);

/*void execute_command(char *command, char **args);*/
void execute_command(char *command, char **args, char *path);
int find_command_in_path(char *command, char *path, char *full_path);

#endif
