#include "mShell.h"

/**
 * _strncat - appends n bytes frm src to dest string
 * @dest: destination string
 * @src: source string
 * @n: number of bytes to concat
 *
 * Return: pointer to dest
 */
char *_strncat(char *dest, char *src, int n)
{
	int i = 0;
	int j = 0;

	while (*dest != '\0')
	{
		dest++;
		i++;
	}
	while (*src != '\0')
	{
		if (j == n)
		{
			break;
		}
		else
		{
			*dest = *(src);
			dest++;
			src++;
			i++;
			j++;
		}
	}

	*dest = '\0';
	dest = dest - i;


	return (dest);
}
/**
 * _strcat - appends src to dest string
 * @dest: destination string
 * @src: source string
 * Return: pointer to dest
 */
char *_strcat(char *dest, char *src)
{
	int i = 0;

	while (*dest != '\0')
	{
		dest++;
		i++;
	}


	while (*src != '\0')
	{
		*dest = *(src);

		dest++;
		src++;
		i++;
	}

	*dest = '\0';
	dest = dest - i;


	return (dest);
}
/**
 * _puts - prints string
 * @str: the string pointer
 *
 * Return: void
 */

void _puts(char *str)
{
	int i = 0;

	while (*str != 0)
	{
		_putchar(*str);
		str++;
		i++;
	}
	_putchar(10);
}
/**
 * _printenv - print env vars
 * @env: environ
 *
 * Return: void
 */
void _printenv(char **env)
{
	int i = 0;

	while (env[i] != NULL)
	{
		_puts(env[i]);
		i++;
	}
}
