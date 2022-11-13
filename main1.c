#include "main.h"
/**
 * main - main func
 *
 * Return: 0
 */
int main(void)
{
	int z = 0;

	while (z == 0)
	{
		printf("$ ");
		z = executOR();
		if (z != 0 && z != 2)
			break;
		if (z == 2)
		{	fflush(stdin);
			continue;
		}
	}
	return (0);
}
