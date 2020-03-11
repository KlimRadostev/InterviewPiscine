#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "header.h"

typedef struct s_node t_node;

t_node	*n(int value)
{
	t_node *root = (t_node *)malloc(sizeof(t_node));
	root->value = value;
	root->right = root->left = 0;
	return (root);
}

t_node	*createTree(int	*arr, int low, int high)
{
	if (low > high)
		return (NULL);

	int mid = (low + high) / 2;
	t_node	*root = n(arr[mid]);

	root->left = createTree(arr, low, mid-1);
	root->right = createTree(arr, mid+1, high);
	return (root);
}

t_node	*createBST(int *arr, int n)
{ return (createTree(arr, 0, n - 1)); }
