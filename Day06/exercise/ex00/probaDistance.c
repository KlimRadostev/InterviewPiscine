#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

#include "header.h"

double	probaDistance(int dist, int *locations, int n)
{
	double	total_paths = 0;
	double	ret = 0;

	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++, total_paths++)
			if (abs(locations[i] - locations[j]) > dist)
				ret++;
	return (ret / total_paths);
}
