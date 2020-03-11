#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#include "header.h"

void	sortArts(struct s_art **arts)
{
	int	total_arts = 0;
	while (*arts) { arts++; total_arts++; }

	struct s_art *arts_t;
	arts_t = (struct s_art *)malloc(sizeof(struct s_art) * total_arts + 1);

	for (int x = -1; x <= total_arts; ++x)
	{
		arts_t->name[x] = (char *)malloc(sizeof(char) * strlen((*arts)->name) + 1);
		strcpy(arts_t->name[x], (*arts)->name[x]);
		arts_t->price[x] = (*arts)->price;
	}

	for (int x = -1; x < total_arts; ++x)
	{
		for (int n = x + 1; n <= total_arts; ++n)
		{
			if (strcmp((*arts)->name[x], arts_t->name[n]) > 0)
			{
				char	*tmpc;
				int		tmpi;
				tmpc = (char *)malloc(sizeof(char) * strlen((*arts)->name[x]) + 1);
				strcpy(tmpc, (*arts)->name[x]);
				tmpi = (*arts)->price[x];
				strcpy((*arts)->name[x], arts_t->name[n]);
				(*arts)->price[x] = arts_t->price[n];
				strcpy(arts_t->name[n], tmpc);
				arts_t->price[n] = tmpi;
				free(tmpc);
			}
		}
	}
}
