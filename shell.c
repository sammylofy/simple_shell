#include "shell.h"

#define MAX_INPUT_SIZE 1024
#define MAX_ARGS 100

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
/**
 * execute_command - Executes the specified command using fork and execve.
 * @command: The command to execute.
 * @args: For arguments
 */
void execute_command(char *command, char **args)
{
	pid_t pid, wpid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	} else if (pid == 0)
	{  /* Child process */
		if (execve(command, args, NULL) == -1)
		{
			perror("./shell ");  /* If execve fails */
			exit(EXIT_FAILURE);
		}
	} else
	{  /* Parent process */
		do {
			wpid = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
}

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
	/*signal(SIGINT, SIG_IGN);  Ignore Ctrl+C for the shell */
	while (1)
	{
		display_prompt();

		read_chars = getline(&input, &input_size, stdin);
		if (read_chars == -1)
		{  /* Handle Ctrl+D (end of file) */
			if (isatty(STDIN_FILENO))
				printf("\n");
			free(input);
			exit(EXIT_SUCCESS);
		}
		if (read_chars > 0 && input[read_chars - 1] == '\n')
			input[read_chars - 1] = '\0';  /* Remove newline character */
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
				execute_command(args[0], args);
			free(input);
			input = NULL;
		}
	}
	return (0);
}
