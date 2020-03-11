#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...
#include <math.h>

#include "header.h"

char	*rightShift(char *bin, int k)
{
	int		i = -1;
	char	*tmp = strdup(bin);
	char	*c = (bin[0] == '1') ? "1" : "0";

	while (++i < k)
	{
		for (int j = 5; j >= 0; j--)
			tmp[j + 1] = tmp[j];
		tmp[0] = c[0];
		tmp[6] = '\0';
	}
	return (tmp);
}

char	*leftShift(char *bin, int k)
{
	int		i = -1;
	char	*tmp = strdup(bin);
	char	*c = (bin[0] == '1') ? "1" : "0";

	while (++i < k)
	{
		tmp[0] = '\0';
		tmp = strcat(&tmp[1], c);
	}
	return (tmp);
}

int	toInt(char *bits)
{
	int tmp = 0;
	int	power = 0;
	int	i = 5;
	int	neg = (bits[0] == '1') ? 1 : 0;

	while (i >= 0)
	{
		if (bits[i] == '1')
			tmp += pow(2, power);
		i--;
		power++;
	}
	return (tmp);
}
