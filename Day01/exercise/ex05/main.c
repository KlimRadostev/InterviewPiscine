#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int main(void)
{
	struct s_tank *tank = initTank();

	/*-------------------
	launch your test here
	--------------------*/
	tankPush(tank, 10);
	printf("%d / 1000 on %d tank\n", tank->stacks[tank->n-1]->sum, tank->n);
	tankPush(tank, 100);
	printf("%d / 1000 on %d tank\n", tank->stacks[tank->n-1]->sum, tank->n);
	tankPush(tank, 10);
	printf("%d / 1000 on %d tank\n", tank->stacks[tank->n-1]->sum, tank->n);
	tankPush(tank, 100);
	printf("%d / 1000 on %d tank\n", tank->stacks[tank->n-1]->sum, tank->n);
	tankPush(tank, 10);
	printf("%d / 1000 on %d tank\n", tank->stacks[tank->n-1]->sum, tank->n);
	tankPush(tank, 100);
	printf("%d / 1000 on %d tank\n", tank->stacks[tank->n-1]->sum, tank->n);
	tankPush(tank, 10);
	printf("%d / 1000 on %d tank\n", tank->stacks[tank->n-1]->sum, tank->n);
	tankPush(tank, 100);
	printf("%d / 1000 on %d tank\n", tank->stacks[tank->n-1]->sum, tank->n);
	tankPush(tank, 10);
	printf("%d / 1000 on %d tank\n", tank->stacks[tank->n-1]->sum, tank->n);
	tankPush(tank, 100);
	printf("%d / 1000 on %d tank\n", tank->stacks[tank->n-1]->sum, tank->n);
	tankPush(tank, 10);
	printf("%d / 1000 on %d tank\n", tank->stacks[tank->n-1]->sum, tank->n);
	tankPush(tank, 100);
	printf("%d / 1000 on %d tank\n", tank->stacks[tank->n-1]->sum, tank->n);
	tankPush(tank, 10);
	printf("%d / 1000 on %d tank\n", tank->stacks[tank->n-1]->sum, tank->n);
	tankPush(tank, 100);
	printf("%d / 1000 on %d tank\n", tank->stacks[tank->n-1]->sum, tank->n);
	tankPush(tank, 10);
	printf("%d / 1000 on %d tank\n", tank->stacks[tank->n-1]->sum, tank->n);
	tankPush(tank, 100);
	printf("%d / 1000 on %d tank\n", tank->stacks[tank->n-1]->sum, tank->n);
	tankPush(tank, 10);
	printf("%d / 1000 on %d tank\n", tank->stacks[tank->n-1]->sum, tank->n);
	tankPush(tank, 100);
	printf("%d / 1000 on %d tank\n", tank->stacks[tank->n-1]->sum, tank->n);
	tankPush(tank, 10);
	printf("%d / 1000 on %d tank\n", tank->stacks[tank->n-1]->sum, tank->n);
	tankPush(tank, 100);
	printf("%d / 1000 on %d tank\n", tank->stacks[tank->n-1]->sum, tank->n);
	tankPush(tank, 10);
	printf("%d / 1000 on %d tank\n", tank->stacks[tank->n-1]->sum, tank->n);
	tankPush(tank, 100);
	printf("%d / 1000 on %d tank\n", tank->stacks[tank->n-1]->sum, tank->n);

	printf("taking battery out of %d tank -> battery %d\n", tank->n, tankPop(tank));
	printf("taking battery out of %d tank -> battery %d\n", tank->n, tankPop(tank));
	printf("taking battery out of %d tank -> battery %d\n", tank->n, tankPop(tank));
	printf("taking battery out of %d tank -> battery %d\n", tank->n, tankPop(tank));
	printf("taking battery out of %d tank -> battery %d\n", tank->n, tankPop(tank));
	printf("taking battery out of %d tank -> battery %d\n", tank->n, tankPop(tank));
	printf("taking battery out of %d tank -> battery %d\n", tank->n, tankPop(tank));
	printf("taking battery out of %d tank -> battery %d\n", tank->n, tankPop(tank));
	printf("taking battery out of %d tank -> battery %d\n", tank->n, tankPop(tank));
	printf("taking battery out of %d tank -> battery %d\n", tank->n, tankPop(tank));
	printf("taking battery out of %d tank -> battery %d\n", tank->n, tankPop(tank));
	printf("taking battery out of %d tank -> battery %d\n", tank->n, tankPop(tank));
	printf("taking battery out of %d tank -> battery %d\n", tank->n, tankPop(tank));
	printf("taking battery out of %d tank -> battery %d\n", tank->n, tankPop(tank));
	printf("taking battery out of %d tank -> battery %d\n", tank->n, tankPop(tank));
	printf("taking battery out of %d tank -> battery %d\n", tank->n, tankPop(tank));
	printf("taking battery out of %d tank -> battery %d\n", tank->n, tankPop(tank));
	printf("taking battery out of %d tank -> battery %d\n", tank->n ,tankPop(tank));
	printf("taking battery out of %d tank -> battery %d\n", tank->n ,tankPop(tank));

	return (0);
}



// Function used for the test
// Don't go further :)
