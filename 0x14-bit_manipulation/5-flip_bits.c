#include "main.h"

/**
 * flip_bits - counts the number of bits to change
 * to get from one number to another
 * @n: first number
 * @m: second number
 *
 * Return: number of bits to change
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int count = 0;
	unsigned long int exclusive = n ^ m;
	unsigned int num_bits = sizeof(unsigned long int) * 8;

	for (unsigned int i = 0; i < num_bits; i++)
	{
		if ((exclusive >> i) & 1)
			count++;
	}

	return (count);
}
