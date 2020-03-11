#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...
#include <stdbool.h>
#include <limits.h>

#include "header.h"

typedef struct s_sellers	t_sellers;

t_sellers	*closestSellers(struct s_graph *parisPlaces, char *youAreHere)
{
	struct s_node		*root = 0;
	if (!*youAreHere) return (0);
	int					i;
	for (i = 0; parisPlaces->places[i]; i++)
		if (!strcmp(youAreHere, parisPlaces->places[i]->name))
			root = parisPlaces->places[i]; // try to find the root node

	if (!root) return (0); //if it doesnt exist GG

	t_sellers			*ret = (t_sellers *)malloc(sizeof(t_sellers));
	ret->distance = INT_MAX;
	ret->placeNames = (char **)malloc(sizeof(char *) * i); //allocate max possible nodes
	bzero(ret->placeNames, sizeof(char *) * i);				//otherwise would have to use realloc

	struct s_queue		*q = queueInit();
	enqueue(q, root);
	if (root->hasCerealBar)
	{
		ret->distance = 0;
		ret->placeNames[0] = root->name;
		return (ret); // check if first node has bar return it if so;
	}
	root->visited = 1;
	int	found = 0;
	while ((root = dequeue(q))) // will iterate throught the whole graph
	{
		for (int i = 0; root->connectedPlaces[i]; i++)
		{
			struct s_node	*tmp = root->connectedPlaces[i];
			if (tmp->visited == 0)
			{
				enqueue(q, tmp);
				tmp->visited = root->visited + 1;   // this will keep the distance;
				if (root->visited <= ret->distance) // this will keep the distance
				{
					if (tmp->hasCerealBar == 1)
					{
						ret->placeNames[found++] = tmp->name;
						ret->distance = root->visited;
					}
				}
			}
		}
	}
	return (ret);
}
