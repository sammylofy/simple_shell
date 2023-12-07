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

char *my_strtok(char *str, const char *delimiters);
int lens(char *word);
void my_print(char *word);


#endif
