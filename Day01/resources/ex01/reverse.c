/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 14:32:02 by kradoste          #+#    #+#             */
/*   Updated: 2019/09/09 14:35:41 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "header.h"

typedef struct s_node t_node;

void	printReverse(struct s_node *lst)
{
	if (lst->next)
	{
		printReverse(lst->next);
		printf(" ");
	}
	printf("%s", lst->word);
}
