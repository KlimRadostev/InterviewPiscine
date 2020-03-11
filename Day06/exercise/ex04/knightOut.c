#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...
#include <math.h>
#include <time.h>
#include <stdbool.h>

#include "header.h"

int		getInitialPos(uint64_t board)
{
	int pos = -1;
	int found = 0;

	for (int i = 0; i < 64; ++i, board >>= 1)
		if (board & 1)
		{
			if (found)
				return (-1);
			pos = i;
		}
	return (pos);
}

double	knightOut(uint64_t board, int n)
{
	double	nBoard[n+1][8][8];
	int		NrthSuth[8] = {2, 2, -2, -2, -1, 1, -1, 1};
	int		EastWest[8] = {-1, 1, -1, 1, 2, 2, -2, -2};

	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			nBoard[0][i][j] = 1.0;

	for (int move = 1; move <= n; move++)
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
			{
				nBoard[move][i][j] = 0.0;
				for (int c = 0; c < 8; c++)
				{
					int posY = NrthSuth[c] + i;
					int posX = EastWest[c] + j;
					if (posY >= 0 && posY < 8 && posX >= 0 && posX < 8)
						nBoard[move][i][j] += nBoard[move-1][posY][posX] / 8.0;
				}
			}
/*	printf("\n");
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
			printf("%lf ", nBoard[n][i][j]);
		printf("\n");
		}*/
	return (1 - nBoard[n][getInitialPos(board) / 8][getInitialPos(board) % 8]);
}
