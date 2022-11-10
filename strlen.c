#include "main.h"

/**
 * _strlen - returns length of string
 * @s: the string pointer
 *
 * Return: length of string
 */
int _strlen(char *s)
{
	int i = 0;

	while (*s != 0)
	{
		s++;
		i++;
	}
	return (i);
}
