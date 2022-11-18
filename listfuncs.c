#include "mShell.h"
/**
 * listAdd - adds word to strlist
 * @word: word from strtok
 * @strlist: linked list
 *
 * Return: 0
 */
int listAdd(char *word, list_st **strlist)
{
	int i = 0;
	list_st *new;

	i = _strlen(word);
	new = malloc(sizeof(list_st));
	if (new == NULL)
	{
		free(new);
		return (0);
	}

	new->str = malloc((sizeof(char) * i) + 1);
	if (new->str == NULL)
	{
		free(new->str);
		return (0);
	}

	new->str = word;
	new->next = NULL;

	if (*strlist == NULL)
	{
		*strlist = new;
	}
	else
	{
		list_st *last = *strlist;

		while (last)
		{
			if (last->next == NULL)
				break;
			last = last->next;
		}
		last->next = new;
	}
	return (0);
}
/**
 * listConvert - convert linked list to string array
 * @strlist: linked list
 *
 * Return: linked list
 */
char **listConvert(list_st **strlist)
{
	int i = 0;
	char **list = NULL;
	list_st *new;

	new = *strlist;
	while (new->next != NULL)
	{
		i++;
		new = new->next;
	}

	list = malloc(sizeof(char *) * i);
	if (!list)
	{
		return (NULL);
	}
	new = *strlist;
	i = 0;
	while (new)
	{
		list[i] = malloc(sizeof(char) * _strlen(new->str));
		if (!list[i])
			return (NULL);
		list[i] = new->str;
		new = new->next;
		i++;
	}
	new = *strlist;
	return (list);
}
/**
 * freelist - frees the list
 * @strlist: char array to free
 *
 * Return: 0
 */
int freelist(list_st *strlist)
{
	list_st *new = strlist;

	while (new)
	{
		list_st *current = new;

		new = new->next;
		if (current->str)
			free(current->str);
		if (current)
			free(current);
	}
	return (0);
}
