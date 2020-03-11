#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

void	swap(struct s_art *node1, struct s_art *node2)
{
	int		value = node1->price;
	char	*str = strdup(node1->name);

	node1->price = node2->price;
	node1->name = strdup(node2->name);

	node2->price = value;
	node2->name = strdup(str);

}

void	heapify(struct s_art **masterpiece, int n, int i)
{
	int	largest = i;
	int	l = 2 * i + 1;
	int	r = 2 * i + 2;

	if (l < n && strcmp(masterpiece[l]->name, masterpiece[largest]->name) > 0)
		largest = l;

	if (r < n && strcmp(masterpiece[r]->name, masterpiece[largest]->name) > 0)
		largest = r;

	if (largest != i)
	{
		swap(masterpiece[i], masterpiece[largest]);
		heapify(masterpiece, n, largest);
	}
}

void	heapSort(struct s_art **masterpiece, int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(masterpiece, n, i);

	for (int i = n - 1; i >= 0; i--)
	{
		swap(masterpiece[0], masterpiece[i]);
		heapify(masterpiece, i, 0);
	}
}
