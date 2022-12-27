#include "mShell.h"
/**
 * _putchar - puts c to stdout
 * @c: character
 *
 * Return: 1 or -1
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * stRemovenl - remove newline from end of str
 * @line: string
 *
 * Return: string with nl turned to 0
 */
char *stRemovenl(char *line)
{
	int i = 0;

	while (line[i] != '\0')
	{
		i++;
	}
	i--;
	line[i] = '\0';
	return (line);
}
/**
 * crunner - all these ops be.. runnin'
 * @s: command
 * @nv: environmen
 * @d: shell datat
 *
 * Return: 1 on success
 */
int crunner(char *s, char **nv, shellData *d)
{
	pid_t pid;
	int val, wai;
	char *argv[] = {NULL, NULL};
	char *env = "env";

	argv[0] = s;
	if (_strcmp(argv[0], env) == 0)
	{	_printenv(nv);
		return (0);
	}
	pid = fork();
	if (pid == -1)
	{	err(d);
		return (0);
	}
	if (pid == 0)
	{       val = execve(argv[0], d->options, nv);
		if (val == -1)
		{	argv[0] = pathFinder(argv[0], nv, d);
			if (argv[0] == NULL)
			{	err(d);
				return (0);
			}
			val = execve(argv[0], d->options, nv);
			if (val == -1)
			{	err(d);
				return (0);
			}
		}
	}
	else
	{
		wait(&wai);
	}
	return (0);
}
/**
 * _strdup - duplicates a string
 * @str: the string to duplicate
 *
 * Return: pointer to the duplicated string
 */
char *_strdup(const char *str)
{
	int length = 0;
	char *ret;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	for (length++; length--;)
		ret[length] = *--str;
	return (ret);
}
/**
* pathFinder -  finds the file in PATH
 * @arg: command to lookup
 * @env: the environment variables
 * @d: shell data
 *
 * Return: full path of file if found, null otherwise
 */
char *pathFinder(char *arg, char **env, __attribute__((unused))shellData *d)
{
	int i = 0, fnd = 0;
	char *saveptr = NULL, *pth = "PATH";
	char eq = '=', col = ':', *line = arg, *old = "OLDPWD";
	DIR *dir;
	struct dirent *sd;

	while (env[i] != NULL)
	{	char *folders = strtok_r(env[i], &eq, &saveptr);
		if (_strcmp(pth, folders) == 0 && fnd == 0)
		{	folders = strtok_r(NULL, &col, &saveptr);
			while (folders && fnd == 0)
			{
				if (folders == NULL)
					break;
				dir = opendir(folders);
				if (dir == NULL)
					return (NULL);
				while ((sd = readdir(dir)) != NULL)
				{
					if (sd == NULL)
						break;
					if (_strcmp(line, sd->d_name) == 0)
					{	char *thPath = folders;
						thPath = _strcat(thPath, "/");
						thPath = _strcat(thPath, sd->d_name);
						fnd = 1;
						closedir(dir);
						return (thPath);
					}
					else
						continue; }
				closedir(dir);
				folders = strtok_r(NULL, &col, &saveptr); }}
		i++;
		if (_strcmp(folders, old) == 0)
			folders = NULL; }
	return (NULL);
}
