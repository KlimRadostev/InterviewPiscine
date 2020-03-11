#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

#include "header.h"

typedef struct s_queue	t_queue;
typedef struct s_node	t_node;

int		isEmpty(t_queue *queue) { return (!queue->first ? 1 : 0); }
char	*peek(t_queue *queue) { return (!queue->first ? queue->first->message : 0); }

t_queue	*queueInit(void)
{
	t_queue	*tmp = malloc(sizeof(t_queue));
	tmp->first = tmp->last = 0;
	return (tmp);
}

char	*dequeue(t_queue *queue)
{
	if (isEmpty(queue)) return (0);
	t_node	*tmp = queue->first;
	void	*ret = queue->first->message;
	queue->first = queue->first->next;
	if (!queue->first) { queue->first = queue->last = 0; }
	free(tmp);
	return (ret);
}

void	enqueue(t_queue *queue, char *message)
{
	t_node	*tmp = malloc(sizeof(t_node));
	tmp->message = message; tmp->next = 0;
	if (isEmpty(queue))
		queue->first = queue->last = tmp;
	else
	{
		queue->last->next = tmp;
		queue->last = tmp;
	}
}
