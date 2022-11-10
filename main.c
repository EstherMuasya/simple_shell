#include "main.h"

/**
 * main - simple shell
 *
 * Return: 0
 */
int main(int ac, char **av, char **env)
{
	int i = 0, z = 0;
	char **fold = NULL;
	unsigned int m = 0, n = 0;
	char *line = NULL, *folders = NULL, eq = '=', col = ':';
	size_t len = 0;
	ssize_t nread;
	char *ex = "exit\n", *pth = "PATH";
	struct stat st;

	while (z == 0)
	{
		_putchar('$');
		_putchar(32);

		nread = getline(&line, &len, stdin);

		while (env[i] != NULL)
		{
			folders = strtok(env[i], &eq);
		//	printf("%s\n", folders);
			if (_strcmp(pth, folders) == 0)
			{
				while (folders)
				{
					folders = strtok(NULL, &eq);
					if (folders == NULL)
						break;

					//_strncat(folders, &slash, 1);
					//_strncat(folders, line, _strlen(line));
					
					//if (stat(folders, &st) == 0)
					//{
					//	printf("YEA\n");
					//}
					opendir(folders);
					printf("%s\n", folders);
				}

			}

			i++;
		}
		if (_strcmp(ex, line) == 0)
		{
			return (0);
		}
	}


	return (0);
}
