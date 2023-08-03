#include "main.h"

/**
 * binary_to_uint - Converts a binary string to an unsigned int
 * @b: Pointer to the binary string
 *
 * Return: The converted number, or 0 if there is an invalid character or b is NULL
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int num = 0;

	if (b == NULL)
		return (0);

	for (; *b; b++)
	{
		if (*b != '0' && *b != '1')
			return (0);

		num = num * 2 + (*b - '0');
	}

	return (num);
}
