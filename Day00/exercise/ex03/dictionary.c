/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 16:13:15 by kradoste          #+#    #+#             */
/*   Updated: 2019/10/16 13:47:52 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

#include "header.h"

size_t	hash(char *input)
{
	unsigned	hash = 0x1337;
	unsigned	i = 0;
	while (input[i] != '\0')
	{
		hash += (hash << 5) - input[i];
		hash -= (hash >> 2) + input[i];
		i++;
	}
	return (hash);
}

t_dict		*dictInit(int capacity)
{
	t_dict	*ret;
	int		i;

	ret = (t_dict *)malloc(sizeof(t_dict));
	ret->capacity = capacity;
	ret->items = (t_item **)malloc(sizeof(t_item *) * capacity);
	i = -1;
	while (++i < capacity)
		ret->items[i] = NULL;
	return (ret);
}

int			dictInsert(t_dict *dict, char *key, t_art *value)
{
	unsigned	h;
	t_item		*item;

	h = hash(key) % (dict->capacity);
	if ((item = dict->items[h]) != NULL)
	{
		while (item->next)
			item = item->next;
		item->next = (t_item *)malloc(sizeof(t_item));
		item = item->next;
	}
	else
	{
		dict->items[h] = (t_item *)malloc(sizeof(t_item));
		item = dict->items[h];
	}
	item->value = value;
	item->key = strdup(key);
	item->next = NULL;
	return (1);
}

t_art	*dictSearch(t_dict *dict, char *key)
{
	unsigned	index;
	t_item		*cursor;

	index = hash(key) % dict->capacity;
	if (!(cursor = dict->items[index]))
		return (NULL);
	while (cursor)
	{
		if (!strcmp(cursor->key, key))
			return (cursor->value);
		cursor = cursor->next;
	}
	return (NULL);
}

int		searchPrice(t_dict *dict, char *name)
{
	t_art	*a;

	a = dictSearch(dict, name);
	if (a != NULL)
		return (a->price);
	else
		return (-1);
}
