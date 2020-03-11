#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

#include "header.h"

char	*NthLastCity(struct s_city *city, int n)
{
	static int	num;
	static char	*tmp;
	if (!city)
	{
		num = 0;
		tmp = NULL;
	}
	else
	{
		NthLastCity(city->next, n);
		if (num == n)
			tmp = city->name;
		num++;
	}
	return (tmp);
}
