#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "header.h"

int searchPrice(struct s_art **arts, char *name)
{
	while (*arts)
	{
		if (!strcmp((*arts)->name, name))
			return ((*arts)->price);
		arts++;
	}
	return (-1);
}
