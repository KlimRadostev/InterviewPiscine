#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "header.h"

typedef struct s_player t_player;

int			playerLen(t_player **players)
{
	int len = 0;
	while (players[len++]);
	return (len - 1);
}

void		merge(t_player **a, t_player **b, int low, int mid, int high)
{
	int l1, l2, i;

	for (l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++)
		if (a[l1]->score <= a[l2]->score)
			b[i] = a[l1++];
		else
			b[i] = a[l2++];
	while (l1 <= mid)
		b[i++] = a[l1++];
	while (l2 <= high)
		b[i++] = a[l2++];
	for (i = low; i <= high; i++)
		a[i] = b[i];
}

void		sort(t_player **a, t_player **b, int low, int high)
{
	int mid;

	if (low >= high)
		return ;
	mid = (low + high) / 2;
	sort(a, b, low, mid);
	sort(a, b, mid+1, high);
	merge(a, b, low, mid, high);
}

t_player	**mergeSort(t_player **players)
{
	int len = playerLen(players);
	t_player	**b = (t_player **)malloc(sizeof(t_player *) * len + 1);
	sort(players, b, 0, len - 1);
	free(b);
	return (players);
}
