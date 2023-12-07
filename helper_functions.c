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
