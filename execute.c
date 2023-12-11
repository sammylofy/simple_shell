#include "shell.h"
/**
 * execute_command - Executes the specified command using fork and execve.
 * @command: The command to execute.
 * @args: For arguments
 */
void execute_command(char *command, char **args)
{
        pid_t pid;
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
                        waitpid(pid, &status, WUNTRACED);
                } while (!WIFEXITED(status) && !WIFSIGNALED(status));
        }
}
