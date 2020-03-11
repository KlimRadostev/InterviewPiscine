#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...
#include <math.h>
#include <time.h>
#include <stdbool.h>

#include "header.h"

double factorial (double n) { return (n == 1 || n == 0) ? 1: n * factorial(n-1); }

int	minPersons(int elements, int minPercentage)
{
	int		people = 1;
	double	percent = people / elements;

	for (; percent <= minPercentage / 100.0; ++people)
		percent += (1 - percent) * people / elements;

	return (people);
}
