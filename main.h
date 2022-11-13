#ifndef MAIN_H
#define MAIN_H
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/wait.h>
struct dirent *readdir(DIR *dirp);

int _putchar(char c);
int executOR(void);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strncat(char *dest, char *src, int n);
#endif
