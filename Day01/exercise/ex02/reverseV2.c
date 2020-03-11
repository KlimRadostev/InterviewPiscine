#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#include "header.h"

typedef struct s_node	t_node;
typedef struct s_item	t_item;
typedef struct s_stack	t_stack;

static bool	isEmpty(t_stack *s) { return (!s->item); }

t_stack	*stackInit()
{
	t_stack	*tmp = malloc(sizeof(t_stack));
	tmp->item = 0;
	return (tmp);
}

void	*pop(struct s_stack *stack)
{
	if (isEmpty(stack))
		return (0);
	t_item	*tmp = stack->item;
	void	*ret = stack->item->word;
	stack->item = stack->item->next;
	free(tmp);
	return (ret);
}

void	push(struct s_stack *stack, char *word)
{
	t_item *tmp = malloc(sizeof(t_item));
	tmp->word = word;
    tmp->next = stack->item;
    stack->item = tmp;
}

void	printReverseV2(struct s_node *lst)
{
	t_stack	*stk = stackInit();
	int		key = 0;

	while (lst)
	{
		push(stk, lst->word);
		lst = lst->next;
	}
	while (!isEmpty(stk))
	{
		if (key)
			printf(" ");
		key = 1;
		printf("%s", pop(stk));
	}
	printf("\n");
}
