#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int main(void)
{

	/*-------------------
	launch your test here
	--------------------*/

	struct s_queue *q = queueInit();

	char	str[] = "Hello";
	char	str1[] = " my name is";
	char	str2[] = " Klim";

	char	str3[] = "Hello";
	char	str4[] = " my name is";
	char	str5[] = " Klim";

	enqueue(q, str);
	enqueue(q, str1);
	enqueue(q, str2);
	printf("%s%s%s%s", dequeue(q), dequeue(q), dequeue(q), dequeue(q));

	enqueue(q, str3);
	enqueue(q, str4);
	enqueue(q, str5);
	printf("%s%s%s%s%s", dequeue(q), dequeue(q), dequeue(q), dequeue(q), dequeue(q));

	return (0);
}



// Function used for the test
// Don't go further :)

