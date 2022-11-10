#include "main.h"
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
