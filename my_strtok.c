#include "shell.h"
#include <stdbool.h>
#include <stddef.h>

char *my_strchr(const char *s, int c);
/**
 * my_strchr - Locate the first occurrence of a character in a string.
 * @s: The string to search.
 * @c: The character to find.
 *
 * Return: A pointer to the first occurrence of the character in the string,
 * or NULL if the character is not found.
 */
char *my_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)

			return ((char *)s);

		s++;
	}
	return (NULL);
}
/**
 * my_strtok - Tokenize a string based on given delimiters.
 * @str: The string to tokenize. On the first call, this should be the string
 *       you want to tokenize. On subsequent calls, this argument should be
 *       NULL.
 * @delimiters: A string containing the delimiter characters.
 *
 * Return: A pointer to the next token in the string, or NULL if there are no
 *         more tokens.
 */

char *my_strtok(char *str, const char *delimiters)
{
	static char *lastToken;
	char *tokenStart;

	if (str != NULL)
	{
		lastToken = str;
	} else if (lastToken == NULL)
	{
		return (NULL);  /* No more tokens*/
	}

	*tokenStart = lastToken;
	while (*lastToken != '\0' && my_strchr(delimiters, *lastToken) != NULL)
	{
		lastToken++;
	}
	if (*lastToken == '\0')
	{
		lastToken = NULL;
		return (NULL);
	}
	/*Find the end of the current token*/
	while (*lastToken != '\0' && my_strchr(delimiters, *lastToken) == NULL)
	{
		lastToken++;
	}
	/* Null-terminate the current token*/
	if (*lastToken != '\0')
	{
		*lastToken = '\0';
		lastToken++;
	}

	return (tokenStart);
}
