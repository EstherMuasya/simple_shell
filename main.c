#include "mShell.h"
/**
 * main - main shell function
 * @ac: number of args
 * @av: arg vector
 * @env: environment
 *	r used for no command(switch)
 *
 * Return: 0
 */
int main(int ac, char **av, char **env)
{
	int r = 0;
	shellData *d;

	d = initData(ac, av, env);
	checkInteractive(d);
	if (d->interAct == 1)
	{	argvgetter(d, av);
		if (d->exitStatus == 0)
			crunner(d->command, env, d);
		d->interAct = 2;
	}
	while (d->exitStatus == 0)
	{
		r = promptgetter(d);
		if (d->exitStatus == 0 && r == 0)
			crunner(d->command, env, d);
		else if (r == 1)
			continue;
		else
			break;
	}
	if (d->interAct != 2)
	{
		if (d->command)
			free(d->command);
		if (d)
			free(d);
	}
	return (0);
}

