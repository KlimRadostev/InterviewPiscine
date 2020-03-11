#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

#include "header.h"

typedef struct s_item	t_item;
typedef struct s_stack	t_stack;

static bool	isEmpty(t_stack *s) { return (!s->item); }

t_stack	*stackInit()
{
	t_stack	*tmp = malloc(sizeof(t_stack));
	tmp->item = 0;
	return (tmp);
}

int		pop(struct s_stack *stack)
{
	if (isEmpty(stack))
		return (0);
	t_item	*tmp = stack->item;
	int		ret = stack->item->idx;
	stack->item = stack->item->next;
	free(tmp);
	return (ret);
}

void	push(struct s_stack *stack, int idx)
{
	t_item	*tmp = malloc(sizeof(t_item));
	tmp->idx = idx;
    tmp->next = stack->item;
    stack->item = tmp;
}

char	*console(void)
{
	t_stack			*s = stackInit();
	char			*line = (char *)malloc(sizeof(char) * 256);
	unsigned long	size = 256;
	char			*buf = line;

	printf("?: ");
	push(s, 0);
	while (getline(&buf, &size, stdin) > 0)
	{
		buf[(int)strlen(buf)-1] = '\0';
		if (!strcmp(buf, "SEND"))
		{
			bzero(&line[s->item->idx], strlen(buf));
			return (line);
		}
		if (!strcmp(buf, "UNDO"))
		{
			int	idx = pop(s);
			if (!idx)
				push(s, 0);
			bzero(&line[s->item->idx], strlen(buf));
		}
		else
			push(s, s->item->idx + strlen(buf));
		printf("%s\n", line);
		printf("\n?: ");
		buf = &line[s->item->idx];
	}
	return (line);
}
