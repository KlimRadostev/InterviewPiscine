#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "header.h"

typedef struct s_info	t_info;
typedef struct s_node	t_node;

int max(int a, int b) { return ((a > b) ? a : b); }

int		getInfoTree(t_info *info, t_node *root)
{
	if (root == NULL)
		return (0);

	else if (root->left != NULL && root->left->value > root->value)
		info->isBST = 0;
	else if (root->right != NULL && root->right->value < root->value)
		info->isBST = 0; //checks if tree is BST

	info->elements++; //elements increase by 1 each time this recurses

	if (root->value > info->max)
		info->max = root->value; //gets max value
	if (root->value < info->min)
		info->min = root->value; //gets min value

	int	lh = getInfoTree(info, root->left); //max left height of tree
	int	rh = getInfoTree(info, root->right); //max right height of tree
	if (lh > rh + 1 || rh > lh + 1)
		info->isBalanced = 0; //if heights dont differ by more than 1 tree is balanced
	return (1 + max(lh, rh)); //return max height + 1 (because of current node)
}

t_info	getInfo(t_node *root)
{
	t_info	ret;

	ret.min = 2147483647;
	ret.max = -2147483648;
	ret.elements = 0;
	ret.isBalanced = 1;
	ret.isBST = 1;
	ret.height = getInfoTree(&ret, root); //initialize all variables

	return (ret);
}
