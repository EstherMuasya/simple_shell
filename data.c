#include "mShell.h"

/**
 * initData - initialize the data struct to default
 * @ac: number of args to main
 * @av: args 2 main
 * @env: environment vars
 *
 * Return: initialized shellData struct pointer
 */
shellData *initData(int ac, char **av, char **env)
{
	shellData *d;
	int i = 0, j = 0;

	while (av[0][i] != '\0')/**i: len of shellname*/
	{
		i++;
	}
	while (env[j] != NULL)/**j: no of vars in env*/
	{
		j++;
	}
	d = malloc(sizeof(struct allvars));
	d->shellName = av[0];
	d->environment = env;
	d->command = NULL;
	d->options = NULL;
	d->argvNo = ac;
	d->exitStatus = 0;
	d->interAct = 0;
/**	d->history = initlist();*/
	return (d);
}
/**
 * checkInteractive - checks whether to run argv
 * @d: shell's data
 *
 * Return: 0
 */
int checkInteractive(shellData *d)
{
	if (d->argvNo > 1)
		d->interAct = 1;
	return (0);
}
/**
 * argvgetter - gets command and options from argv
 * @d: shell's data
 * @av: main's arguments
 *
 * Return: 0
 */
int argvgetter(shellData *d, char **av)
{
	int i = 0;
	char **opt;
	char *exit = "exit";

	while (av[1][i] != '\0')
	{
		i++;
	}
	opt = av;
	opt = opt + 1;
	d->options = opt;
	d->command = av[1];
	if (_strcmp(av[1], exit) == 0)
	{	d->exitStatus = 1;
		return (0);
	}
	return (0);
}
/**
 * promptgetter - displays prompt, gets cmd and opt
 * @d: shell's data
 *
 * Return: 0
 */
int promptgetter(shellData *d)
{
	int input;
	size_t len = 0;
	char *line = NULL, *exit = "exit"; 
	char **argv = NULL;

	_putchar('$');
	_putchar(32);
	input = getline(&line, &len, stdin);
	if (input == -1)
	{	free(line);
		perror("input");
		d->exitStatus = 1;
		return (0);
	}
	if (input == 1)
	{
		free(line);
		return (0);
	}
	line = stRemovenl(line);
	if (_strcmp(exit, line) == 0)
	{	free(line);
		d->exitStatus = 1;
		return (0);
	}
	argv = strtow(line);
	d->command = _strdup(argv[0]);
	d->options = &argv[1];

	if (line)
		free(line);
	return (0);
}
