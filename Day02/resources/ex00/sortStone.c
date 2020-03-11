#include <time.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

#include "header.h"

typedef struct s_stone t_stone;

void	sortStones(struct s_stone **stone)
{
	int		data[1000] = {0};
	int		size[1000] = {0};
	int		total;
	t_stone	*tmp = stone[0];

	for (total = -1; tmp; tmp = tmp->next, size[total]++)
		if (data[total] != tmp->size)
			data[++total] = tmp->size;
	for (int k = 0; k < total; k++)
		for (int i = 0; i < total - k; i++)
			if (data[i] > data[i+1])
			{
				int tmp1 = size[i];
				size[i] = size[i+1];
				size[i+1] = tmp1;
				int tmp2 = data[i];
				data[i] = data[i+1];
				data[i+1] = tmp2;
			}
	tmp = stone[0];
	for (int k = 0; data[k]; k++)
		while (size[k] != 0)
		{
			tmp->size = data[k];
			size[k]--;
			tmp = tmp->next;
		}
}
