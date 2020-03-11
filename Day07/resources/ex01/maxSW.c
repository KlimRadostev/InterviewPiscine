#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...
#include <limits.h>
#include <stdbool.h>
#include <math.h>

#include "header.h"

typedef struct s_dequeNode	t_dequeNode;
typedef struct s_deque		t_deque;
typedef struct s_max		t_max;

bool	isEmpty(t_deque *deque) { return (!deque->first && !deque->last); }
int		peakFront(t_deque *deque) { return (!isEmpty(deque) ? deque->first->value : INT_MIN); }
int		peakBack(t_deque *deque) { return (!isEmpty(deque) ? deque->last->value : INT_MIN); }

t_deque	*dequeInit(void)
{
	t_deque	*tmp = (t_deque *)malloc(sizeof(t_deque));
	tmp->first = tmp->last = 0;
	return (tmp);
}

void	pushFront(t_deque *deque, int value)
{
	t_dequeNode	*tmp = (t_dequeNode *)malloc(sizeof(t_dequeNode));
	tmp->value = value;
	if (isEmpty(deque))
	{
		deque->first = deque->last = tmp;
		tmp->next = tmp->prev = NULL;
	}
	else
	{
		tmp->prev = deque->first;
		deque->first->next = tmp;
		tmp->next = NULL;
		deque->first = tmp;
	}
}

void	pushBack(t_deque *deque, int value)
{
	t_dequeNode	*tmp = (t_dequeNode *)malloc(sizeof(t_dequeNode));
	tmp->value = value;
	if (isEmpty(deque))
	{
		deque->first = deque->last = tmp;
		tmp->next = tmp->prev = NULL;
	}
	else
	{
		tmp->next = deque->last;
		deque->last->prev = tmp;
		tmp->prev = NULL;
		deque->last = tmp;
	}
}

int		popFront(t_deque *deque)
{
	if (isEmpty(deque)) return (INT_MIN);
	t_dequeNode	*tmp = deque->first;
	int			ret = deque->first->value;
	deque->first = deque->first->prev;
	if (!deque->first)
		deque->first = deque->last = NULL;
	else
		deque->first->next = NULL;
	tmp->prev = NULL;
	free(tmp);
	return (ret);
}

int		popBack(t_deque *deque)
{
	if (isEmpty(deque)) return (INT_MIN);
	t_dequeNode *tmp = deque->last;
	int			ret = deque->last->value;
	deque->last = deque->last->next;
	if (!deque->last)
		deque->last = deque->first = NULL;
	else
		deque->last->prev = NULL;
	tmp->next = NULL;
	free(tmp);
	return (ret);
}

t_max	*maxSlidingWindow(int *arr, int n, int k)
{
	t_max	*window = (t_max *)malloc(sizeof(t_max));
	t_deque	*dq = dequeInit();
	window->max = (int *)malloc(sizeof(int) * (n - k + 1));
	window->length = n - k + 1;

	for (int i = 0; i < k; i++)
	{
		while (!isEmpty(dq) && peakBack(dq) <= arr[i])
			popBack(dq);
		pushBack(dq, i);
	}
	for (int i = k; i <= n; i++)
	{
		window->max[i - k] = arr[peakFront(dq)];
		while (!isEmpty(dq) && peakFront(dq) <= i - k)
			popFront(dq);
		while (!isEmpty(dq) && arr[peakBack(dq)] <= arr[i])
			popBack(dq);
		pushBack(dq, i);
	}
	return (window);
}

/*
int main()
{
	t_deque	*dq = dequeInit();

	pushFront(dq, 4);
	pushFront(dq, 4);
	pushFront(dq, 4);
	pushBack(dq, 5);
	pushBack(dq, 5);
	pushBack(dq, 5);

	printf("%d\n", popFront(dq));
	printf("%d\n", popFront(dq));
	printf("%d\n", popFront(dq));
	printf("%d\n", popFront(dq));
	printf("%d\n", popFront(dq));
	printf("%d\n", popFront(dq));
	printf("%d\n", popFront(dq));

	pushFront(dq, 4);
	pushFront(dq, 4);
	pushFront(dq, 4);
	pushBack(dq, 5);
	pushBack(dq, 5);
	pushBack(dq, 5);
	pushFront(dq, 4);
	pushFront(dq, 4);
	pushFront(dq, 4);
	pushBack(dq, 5);
	pushBack(dq, 5);
	pushBack(dq, 5);

	printf("%d\n", popBack(dq));
	printf("%d\n", popBack(dq));
	printf("%d\n", popBack(dq));
	printf("%d\n", popBack(dq));
	printf("%d\n", popBack(dq));
	printf("%d\n", popBack(dq));
	printf("%d\n", popBack(dq));
	printf("%d\n", popBack(dq));
	printf("%d\n", popBack(dq));
	printf("%d\n", popBack(dq));
	printf("%d\n", popBack(dq));
	printf("%d\n", popBack(dq));
	printf("%d\n", popBack(dq));
	printf("%d\n", popBack(dq));

	return (0);
}
*/
