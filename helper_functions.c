#include "shell.h"

/**
 * lens - function to calculate the length of word
 * @word: characters
 * Return: int value
 *
 * Description: The length
 */
int lens(char *word)
{
	int length = 0;
	int i;

	i = 0;
	while (word[i] != '\0')
	{
		length++;
		i++;
	}
	return (length);
}
/**
 * my_print - Prints a string character by character.
 * @word: The input string to print.
 */
void my_print(char *word)
{
	int size, i;

	size = lens(word);
	i = 0;
	while (i < size)
	{
		write(1, &word[i], 1);
		i++;
	}
}
/**
 * comp_str - checks whether the both strings are
 * the same
 * @first: the first string to compare
 * @second: the second string to compare
 * Return: 1 or 0 is returned
 *
 * Description: Returns 0 if the same or 1
 * if otherwise
 */
int comp_str(char *first, char *second)
{
	int i = 0;

	while (first[i] && second[i])
	{
		if (first[i] != second[i])
		{
			return (1);
		}
		i++;
	}

	if (first[i] != second[i])
	{
		return (1);
	}

	return (0);
}

/**
 * print_environment - Prints the current environment.
 * Description:prints d enviromental variables.
 */

void print_environment(void)
{
	char **env = environ;

	for (; *env != NULL; env++)
	{
		write(STDOUT_FILENO, *env, lens(*env));
		write(STDOUT_FILENO, "\n", 1);
	}
}
