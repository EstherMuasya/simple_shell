#include "mShell.h"

/**
 * _strlen - returns length of string
 * @s: the string pointer
 *
 * Return: length of string
 */
int _strlen(char *s)
{
	int i = 0;
	char *str = s;

	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
/**
 * splitlen - counts words in string
 * @str: the string
 *-
 * Return: number of words in string
 */
int splitlen(char *str)
{
	int l, i = 0;
	char *s = str;

	while (s[i] != '\0')
	{
		while (s[i] != 32 && s[i] != '\0')
			i++;
		if (s[i + 1] == 32)
			i++;
		l++;
		i++;
	}
	return (l);
}
/**
 * strtow - splits a string to words
 * @str: string to split
 *
 * Return: pointer to array of words or NULL
 */
char **strtow(char *str)
{
	list_st *strlist = NULL;
	char *word;
	char **wordlist;
	char spc = ' ';

	word = strtok(str, &spc);
	listAdd(word, &strlist);
	while ((word = strtok(NULL, &spc)))
	{
		listAdd(word, &strlist);
	}
	wordlist = listConvert(&strlist);
	return (wordlist);
}
/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: difference
 */
int _strcmp(char *s1, char *s2)
{
	while ((*s1 != '\0' && *s2 != '\0') && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	if (*s1 == *s2)
	{
		return (0);
	}
	else
	{
		return (*s1 - *s2);
	}
}

/**
 * is_delim - checks if character is a delimeter
 * @c: the char to check
 * @delim: the delimeter string
 * Return: 1 if true, 0 if false
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}
