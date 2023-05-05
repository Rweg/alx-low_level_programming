#include "main.h"

/**
 * flip_bits - counts the number of bits to change
 * to get from one number to another
 * @n: first number
 * @m: second number
 *
 * Return: Returns the number of bits to flip
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int i, counter = 0;
	unsigned long int current;
	unsigned long int diff = n ^ m;

	for (i = 63; i >= 0; i--)
	{
		current = diff >> i;
		if (current & 1)
			counter++;
	}

	return (counter);
}
