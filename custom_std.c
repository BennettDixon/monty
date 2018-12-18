#include <stdlib.h>
/**
 * _strlen - calculates the length of a string
 * @str: string to get length of
 *
 * Return: length of string (size_t)
 */
size_t _strlen(char *str)
{
	size_t len = 0;

	while (str[len++])
		;
	return (len);
}
