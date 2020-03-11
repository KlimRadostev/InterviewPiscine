#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

#include "header.h"

int	selectHotspots(struct s_hotspot **hotspots)
{
	int	count = 1;

	struct s_hotspot	*this = hotspots[0];
	for (int i = 1; hotspots[i]; i++)
		if (hotspots[i]->pos - hotspots[i]->radius >= this->pos + this->radius)
		{
			count++;
			this = hotspots[i];
		}
	return (count);
}
