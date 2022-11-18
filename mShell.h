#ifndef MSHELL_H
#define MSHELL_H

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/wait.h>
#include <errno.h>
/**
 * struct liststr - singly linked list of strings
  * @str: the string
  * @next: the next string
  */
typedef struct liststr
{
	char *str;
	struct liststr *next;
} list_st;

struct dirent *readdir(DIR *dirp);

/**
 * struct allvars - all the main shell variables
 * @shellName: name of the shell's executable
 * @command: current command's full path
 * @options: array of current command's options
 * @argvNo: Total number of variables supplied
 * @environment: array of env variables
 * @exitStatus: exit anytime this is 1
 *		loop while 0
 * @interAct: if 1, execute main arguments, turn 0.
 *		if 0, display prompt and execute input
 * @history: linked list containing the history of commands
 */
typedef struct allvars
{
	char *shellName;
	char *command;
	char **options;
	char **environment;
	int argvNo;

	int exitStatus;
	int interAct;

	list_st history;

} shellData;

/** utility functions */
int _putchar(char c);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
int splitlen(char *str);
char **arrstr(char *str, int len);
char *_strncat(char *dest, char *src, int n);
char *_strcat(char *dest, char *src);
char **strtow(char *str);
int is_delim(char c, char *delim);

int listAdd(char *word, list_st **strlist);
char **listConvert(list_st **strlist);
char *stRemovenl(char *line);
int freelist(list_st *strlist);
char *_strdup(const char *str);
/** shell functions*/
shellData *initData(int ac, char **av, char **env);

int argvgetter(shellData *, char **av);
int promptgetter(shellData *);
int crunner(char *, char **env, shellData *);
int checkInteractive(shellData *);

char *pathFinder(char *arg, char **env, shellData *);
void err(shellData *);
void _puts(char *str);
void _printenv(char **env);
#endif
