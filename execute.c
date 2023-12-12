#include "shell.h"
/**
 * execute_command - Executes the specified command using fork and execve.
 * @command: The command to execute.
 * @args: For arguments
 * @path: for path
 */
void execute_command(char *command, char **args, char *path)
{
	pid_t pid;
	int status;
	char full_path[MAX_INPUT_SIZE];

	if (access(command, X_OK) == 0)
	{
		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		} else if (pid == 0)
		{  /* Child process */
			if (execve(command, args, NULL) == -1)
			{
				perror("./hsh ");  /* If execve fails */
				exit(EXIT_FAILURE);
			}
		} else
		{  /* Parent process */
			do {
				waitpid(pid, &status, WUNTRACED);
			} while (!WIFEXITED(status) && !WIFSIGNALED(status));
		}
	} else if (find_command_in_path(command, path, full_path))
	{
		execute_command(full_path, args, path);
	} else
	{
		char error_message[MAX_INPUT_SIZE];

		sprintf(error_message, "%s: command not found\n", command);
	}
}
