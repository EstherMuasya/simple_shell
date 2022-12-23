#include "mShell.h"
/**
 * listAdd - adds word to str-linked list
 * @word: word from strtok
 * @strlist: linked list
 *
 * Return: 0
 */
int listAdd(char *word, list_st **strlist)
{
	list_st *new;

	new = malloc(sizeof(list_st));
	if (new == NULL)
	{
		free(new);
		return (0);
	}

	new->str = strdup(word);
	if (new->str == NULL)
	{
		free(new->str);
		return (0);
	}

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
 * Return: string array
 */
char **listConvert(list_st **strlist)
{
	int i = 0;
	char **list = NULL;
	list_st *new;

	new = *strlist;
	i++;
	while (new->next != NULL)
	{
		i++;
		new = new->next;
	}
	list = malloc((sizeof(char *) * (i + 1)));
	if (!list)
	{	free (list);
		return (NULL);
	}
	new = *strlist;
	i = 0;
	while (new)
	{
		int m = _strlen(new->str);

		if (m > 0)
		{	list[i] = strdup(new->str);
			if (!list[i])
				return (NULL);
			new = new->next;
			i++;
		}
	}
	list[i] = NULL;
	return (list);
}
/**
 * freelist - frees the list
 * @strlist: linked list to free
 *
 * Return: 0
 */
int freelist(list_st **strlist)
{
	list_st *strl = *strlist;

	while (strl)
	{
		list_st *c = strl;

		strl = strl->next;
		if (c->str)
			free(c->str);
		if (c)
			free(c);
	}
	return (0);
}
