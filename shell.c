#include "shell.h"

/**
 * main - function to perform basic shell operations
 * @argc: argument count
 * @argv: arguments COMMAND-LINE args
 * @env: Environmental Variables
 * Return: Always 0
 *
 * Description: basic simple shell operations
 */

int main(int argc, char **argv, char **env)
{
	char *buffer = NULL;
	size_t buf_size = 0, read;
	char **array = NULL;

	if (isatty(STDIN_FILENO))
		write(1, "$ ", 3);
	fflush(stdout);
	read = getline(&buffer, &buf_size, stdin);

	

}

/**
 * free_on_read - function to free the memory
 * @read: The amount read
 * @buf: the buffer
 *
 * Description: To exit
 * Return: no return
 */
void free_on_read(size_t read, char *buf)
{
	if (read == (size_t) -1)
	{
		if (isatty(STDIN_FILENO))
			write(1, "\n", 1);
		free(buf);
		exit(EXIT_FAILURE);
	}
	if (buf[read - 1] == '\n')
		buf[read - 1] = '\0';
}
