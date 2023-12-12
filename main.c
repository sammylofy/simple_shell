#include "shell.h"

void display_prompt(void);
/**
 * main - function to perform basic shell operations
 * Return: Always 0
 *
 * Description: basic simple shell operations
 */
int main(void)
{
	char *input = NULL;
	size_t input_size = 0;
	ssize_t read_chars;
	const char *delim = ": ";
	char *path = getenv("PATH");

	if (path == NULL) {
		write(STDERR_FILENO, "Error: PATH environment variable not set\n", 41);
		exit(EXIT_FAILURE);
	}

	/*signal(SIGINT, SIG_IGN);  Ignore Ctrl+C for the shell */
	while (1)
	{
		display_prompt();

		read_chars = getline(&input, &input_size, stdin);
		if (read_chars == -1)
		{  /* Handle Ctrl+D (end of file) */
			if (isatty(STDIN_FILENO))
				my_print("\n");
			free(input);
			exit(EXIT_SUCCESS);
		}
		if (read_chars > 0 && input[read_chars - 1] == '\n')
			input[read_chars - 1] = '\0';  /* Remove newline character */
		if (comp_str(input, "exit") == 0)
		{
			free(input);
			exit(EXIT_SUCCESS);
		}
		if (lens(input) > 0)
		{
			char *token;
			char *args[MAX_ARGS];
			int arg_count = 0;

			token = strtok(input, delim);
			while (token != NULL && arg_count < MAX_ARGS - 1)
			{
				args[arg_count] = token;
				arg_count++;
				token = strtok(NULL, delim);
			}
			args[arg_count] = NULL;
			if (args[0] != NULL)
				execute_command(args[0], args, path);
			free(input);
			input = NULL;
		}
	}
	return (0);
}
/**
 * display_prompt - Displays the shell prompt if the input is from a terminal.
 */
void display_prompt(void)
{
	if (isatty(STDIN_FILENO))
	{
		my_print("$ ");
		fflush(stdout);
	}
}
