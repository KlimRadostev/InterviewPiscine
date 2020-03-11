#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

typedef struct s_node	t_node;

t_node	*node(int n)
{
	t_node	*new = (t_node *)malloc(sizeof(t_node));
	new->value = n;
	new->right = new->left = 0;
	return (new);
}

t_node	*createIT(int *arr, int l, int r)
{
	if (!arr || l > r)
		return (NULL);
	int mid = (l + r) / 2;
	t_node	*root = node(arr[mid]);
	root->left = createIT(arr, l, mid - 1);
	root->right = createIT(arr, mid + 1, r);
	return (root);
}

t_node	*createBST(int *arr, int n)
{
	return (createIT(arr, 0, n - 1));
}
