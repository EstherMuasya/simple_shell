#include "main.h"

/**
 * main - simple shell
 *
 * Return: 0
 */
int main(int ac, char **av, char **env)
{
	int i = 0, z = 0, x = 1, fnd = 0;
	unsigned int m = 0, n = 0;
	size_t len = 0;
	ssize_t nread;
	char **fold = NULL, *line = NULL, *folders = NULL;
	char eq = '=', col = ':', nl = '\n';
	char *ex = "exit\n", *pth = "PATH", *saveptr;
	struct stat st;
	struct dirent *sd;
	DIR *dir;

	while (z == 0)
	{
		_putchar('$');
		_putchar(32);

		nread = getline(&line, &len, stdin);
		printf("Your input command is %s Let's search for it in path\n", line);

		while (env[i] != NULL)
		{
			folders = strtok_r(env[i], &eq, &saveptr);
			if (_strcmp(pth, folders) == 0 && fnd == 0)
			{
			
				folders = strtok_r(NULL, &col, &saveptr);
				while (folders && fnd == 0)
				{
					if (folders == NULL)
						break;

					dir = opendir(folders);
					if(dir == NULL)
                                        {
                                                printf("unable to open dir");
                                                return(-1);
                                        }

                                        while(x = 1)
					{
						sd = readdir(dir);
						if (sd == NULL)
						{
							break;
						}
						line = strtok(line, &nl);

						if(_strcmp(line, sd->d_name) == 0)
						{
							printf("found %s, in %s, now we can stop\n", sd->d_name, folders);
							x = 0;
							fnd = 1;
							break;
						}
                                              	else
						{
							continue;
                                                }
					}
					if (fnd == 1 && x == 0)
						break;

	                                closedir(dir);

					folders = strtok_r(NULL,&col, &saveptr);
					if (folders)
						printf("looking for the input in: %s\n", folders);
					else
						printf("NULL folder coz its at the end\n");
				}
			}	
			i++;
		}
	
		if (_strcmp(ex, line) == 0)
			return (0);
		
	}
	return (0);
}
