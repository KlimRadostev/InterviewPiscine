#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...
#include <stdbool.h>
#include <math.h>
#include <time.h>

#include "header.h"

char	*getNeg(char *str)
{
	int i = 0;
	while (str[++i])
		if (str[i] == '1')
			str[i] = '0';
		else
			str[i] = '1';
	return (&str[1]);
}

char	*getAnd(char *a, char *b)
{
	char	*ret = malloc(sizeof(char) * 4 + 1);
	a = (a[0] == '~') ? getNeg(a) : a;
	b = (b[0] == '~') ? getNeg(b) : b;
	for (int i = 0; i < 4; i++)
		if (a[i] == '1' && b[i] == '1')
			ret[i] = '1';
		else
			ret[i] = '0';
	ret[4] = '\0';
	return (ret);
}

char	*getOr(char *a, char *b)
{
	char	*ret = malloc(sizeof(char) * 4 + 1);
	a = (a[0] == '~') ? getNeg(a) : a;
	b = (b[0] == '~') ? getNeg(b) : b;
	for (int i = 0; i < 4; i++)
		if (a[i] == '1' || b[i] == '1')
			ret[i] = '1';
		else
			ret[i] = '0';
	ret[4] = '\0';
	return (ret);
}

int	toInt(char *bits)
{
	int tmp = 0;
	int	power = 0;
	int	i = 3;

	while (i >= 0)
	{
		if (bits[i] == '1')
			tmp += pow(2, power);
		i--;
		power++;
	}
	return (tmp);
}
