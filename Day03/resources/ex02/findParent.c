#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...
#include <time.h>
#include <stdbool.h>

#include "header.h"

typedef struct	s_node t_node;

typedef struct	s_item {
	t_node			*node;
	struct s_item	*next;
}				t_item;

typedef struct	s_queue {
	t_item	*first;
	t_item	*last;
}				t_queue;

static int		isEmpty(t_queue *queue) { return (!queue->first ? 1 : 0); }
//static t_node	*peek(t_queue *queue) { return (!queue->first ? queue->first->node : 0); }

static t_queue	*queueInit(void)
{
	t_queue	*tmp = malloc(sizeof(t_queue));
	tmp->first = tmp->last = 0;
	return (tmp);
}

static t_node	*dequeue(t_queue *queue)
{
	if (isEmpty(queue)) return (0);
	t_item	*tmp = queue->first;
	t_node	*ret = queue->first->node;
	queue->first = queue->first->next;
	if (!queue->first) { queue->first = queue->last = 0; }
	free(tmp);
	return (ret);
}

static void		enqueue(t_queue *queue, t_node *node)
{
	t_item	*tmp = malloc(sizeof(t_item));
	tmp->node = node; tmp->next = 0;
	if (isEmpty(queue))
		queue->first = queue->last = tmp;
	else
	{
		queue->last->next = tmp;
		queue->last = tmp;
	}
}

int				findStr(t_node *root, t_queue *queue, char *str)
{//this function will find the common string in the tree
	int tmp = 0;
	for (int i = 0; root->children[i]; i++)
	{
		if (!strcmp(str, root->children[i]->name))
		{
			enqueue(queue, root->children[i]);
			return (1);
		}
		if ((tmp = findStr(root->children[i], queue, str)))
		{
			enqueue(queue, root->children[i]);
			return (tmp + 1);
		}
	}
	return (tmp);
}

t_node			*findParent(t_node *root, char *firstSpecies, char *secondSpecies)
{
	t_queue	*firstS = queueInit();
	t_queue *secondS = queueInit();
	int		firstD = 0;
	int		secondD = 0;

	if (!(firstD = findStr(root, firstS, firstSpecies)))
		return (NULL);
	if (!(secondD = findStr(root, secondS, secondSpecies)))
		return (NULL);
	enqueue(firstS, root);
	enqueue(secondS, root);

	while (firstS || secondS)
		if (!strcmp(firstS->first->node->name, secondS->first->node->name))
			return (firstS->first->node);
		else if (firstD > secondD)
		{
			firstD--;
			dequeue(firstS);
		}
		else if (secondD > firstD)
		{
			secondD--;
			dequeue(secondS);
		}
		else
		{
			firstD--; secondD--;
			dequeue(secondS); dequeue(firstS);
		}	
	return (NULL);
}
