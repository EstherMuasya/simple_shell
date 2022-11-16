#include "mShell.h"
/**
 * main - main shell function
 * @ac: number of args
 * @av: arg vector
 * @env: environment
 *
 * Return: 0
 */
int main(int ac, char **av, char **env)
{
	shellData *d;

	d = initData(ac, av, env);
	checkInteractive(d);
	if (d->interAct == 1)
	{	argvgetter(d, av);
		if (d->exitStatus == 0)
			crunner(d->command, env);
		d->interAct = 0;
	}
	while (d->exitStatus == 0)
	{
		promptgetter(d);
		if (d->exitStatus == 0)
			crunner(d->command, env);
		else
			break;
	}
	free(d);
	return (0);
}

