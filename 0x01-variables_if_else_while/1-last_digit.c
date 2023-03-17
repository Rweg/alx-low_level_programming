#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int n;
	int las_d;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	las_d = n % 10;

	if (las_d > 5)
	{
		printf("Last digit of %d is %d and is greater than 5 and not 0\n", n, las_d);
	}
	else if (las_d < 6 && las_d != 0)
	{
		printf("Last digit of %d is %d and is less than 6 and not 0\n", n, las_d);
	}
	else
	{
		printf("Last digit of %d  is %d and is 0\n", n, las_d);
	}
	return (0);
}
