#include "main.h"
/**
 * executOR - gets a line and executes it
 *
 * Return: 0 to continue, 1 to exit, 2 special
 */
int executOR(void)
{
	pid_t pid;
	size_t len = 0;
	char *filename = NULL, *ex = "exit";
	char nl = '\n';
	char *argv[] = {"", NULL};
	int nread, val;

	nread = getline(&filename, &len, stdin);
	if (nread == -1 || nread == 1)
	{	free(filename);
		printf("error\n");
		return (2);
	}
	filename = strtok(filename, &nl);
	if (_strcmp(ex, filename) == 0)
	{	free(filename);
		return (1);
	}
	argv[0] = filename;
	pid = fork();
	if (pid == -1)
	{	perror("Error");
		return (0);
	}
	if (pid == 0)
	{	val = execve(argv[0], argv, NULL);
		if (val == -1)
		{	perror("Error");
			return (0);
		}
	}
	else
	{	wait(NULL);
		return (0);
	}
	free(filename);
	return (0);
}
