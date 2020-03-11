#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

#include "header.h"

char	*getSum(char *a, char *b)
{
	char *sum = malloc(sizeof(char) * 6 + 1);
	for (int i = 0; i < 6; i++)
		if (a[i] == '1' || b[i] == '1')
			sum[i] = '1';
		else
			sum[i] = '0';
	sum[6] = '\0';

	return (sum);
}

int		toInt(char *bits)
{
	int tmp = 0;
	int	power = 0;
	int	i = 5;

	while (i >= 0)
	{
		if (bits[i] == '1')
			tmp += pow(2, power);
		i--;
		power++;
	}
	return (tmp);
}
