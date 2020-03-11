/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precious.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 03:41:29 by kradoste          #+#    #+#             */
/*   Updated: 2019/09/09 05:29:20 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "header.h"

typedef struct s_node t_node;

t_node	*n(char c)
{
	t_node	*tmp = malloc(sizeof(t_node));
	tmp->c = c;
	tmp->prev = tmp->next = 0;
	return (tmp);
}

char	*precious(int *text, int size)
{
	char	*s = CS;
	t_node	*loop = n(s[0]);
	t_node	*tmp = loop;

	for (int i = 1; i < (int)strlen(s); i++)
	{
		t_node	*x = n(s[i]);
		tmp->next = x;
		x->prev = tmp;
		tmp = tmp->next;
	}
	tmp->next = loop;
	loop->prev = tmp;

	char	*str = (char *)malloc(sizeof(char) * size + 1);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < abs(text[i]); j++)
			loop = (text[i] > 0) ? loop->next : loop->prev;
		str[i] = loop->c;
	}
	str[size] = '\0';
	return (str);
}
