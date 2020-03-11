#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...
#include <time.h>
#include <math.h>

#include "header.h"

double	probabilityWin(double firstDollarsBet, double dollarsWanted, int nbGame)
{
	if (firstDollarsBet >= dollarsWanted)
		return (1.0);
	else if (nbGame <= 0)
		return (0.0);

	double	tmpWin = 18.0/37;
	double	tmpDraw = 1.0/37;

	if (nbGame > 0)
	{
		tmpWin *= probabilityWin(firstDollarsBet * 2, dollarsWanted, nbGame - 1);
		tmpDraw *= probabilityWin(firstDollarsBet / 2, dollarsWanted, nbGame - 1);
	}
	return (tmpWin + tmpDraw);
}
