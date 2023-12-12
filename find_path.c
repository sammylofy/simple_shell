#include "shell.h"
/**
 * find_command_in_path - Finds the command in the path
 * @command: the command provided
 * @path: The realtive path
 * @full_path: The absolute path
 *
 * Return: on Success 1 is returned
 */
int find_command_in_path(char *command, char *path, char *full_path)
{
	char *token;
	struct stat st;

	token = strtok(path, ":");
	while (token != NULL)
	{
		sprintf(full_path, "%s/%s", token, command);

		if (stat(full_path, &st) == 0 &&
				S_ISREG(st.st_mode) &&
				(st.st_mode & S_IXUSR))
			return (1);
		token = strtok(NULL, ":");
	}
	return (0);
}
