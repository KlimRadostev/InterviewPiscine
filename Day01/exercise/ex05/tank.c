#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

#include "header.h"

typedef struct s_item	t_item;
typedef struct s_stack	t_stack;
typedef struct s_tank	t_tank;

t_tank	*initTank(void)
{
	t_tank	*tmp = malloc(sizeof(t_tank));
	tmp->stacks = malloc(sizeof(t_stack *));
	tmp->stacks[0] = malloc(sizeof(t_stack));
	tmp->n = 1;
	return (tmp);
}

void	tankPush(t_tank *tank, int energy)
{
	if (energy < 10 || energy > 100) return ;

	t_item	*tmp = malloc(sizeof(t_item));
	tmp->energy = energy;
	t_item	*top = tank->stacks[tank->n-1]->item;
	tmp->next = top;

	t_stack	*top_tank = tank->stacks[tank->n-1];
	if (tank->stacks[tank->n-1]->sum + energy > 1000)
	{
		tank->n += 1;
		tank->stacks = realloc(tank->stacks, tank->n * sizeof(t_stack *));
		tank->stacks[tank->n-1] = malloc(sizeof(t_stack));
		top_tank = tank->stacks[tank->n-1];
		top_tank->sum = energy;
		top_tank->item = tmp;
	}
	else
	{
		top_tank = tank->stacks[tank->n-1];
		top_tank->sum += energy;
		top_tank->item = tmp;
	}
}

int		tankPop(t_tank *tank)
{
	if (!tank->stacks[tank->n-1]->item) return (0);
	t_item	*tmp = tank->stacks[tank->n-1]->item;
	int		ret = tmp->energy;
	t_stack	*top_tank = tank->stacks[tank->n-1];

	if (tank->stacks[tank->n-1]->sum - tmp->energy == 0)
	{
		free(tmp);
		if (tank->n == 1)
		{
			free(tank->stacks[0]);
			tank->stacks[0] = malloc(sizeof(t_stack));
			tank->stacks[0]->sum = 0;
			tank->stacks[0]->item = 0;
		}
		else
		{
			free(top_tank);
			tank->stacks = realloc(tank->stacks, tank->n * sizeof(t_stack *));
			tank->n -= 1;
		}
	}
	else
	{
		t_stack *top_tank = tank->stacks[tank->n-1];
		top_tank->sum -= tmp->energy;
		top_tank->item = tmp->next;
		free(tmp);
	}
	return (ret);
}
