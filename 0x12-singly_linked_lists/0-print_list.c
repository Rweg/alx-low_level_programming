#include <stdio.h>
#include "lists.h"

/**
 * print_list -this prints all elements of the linked list
 * @head:is the pointer to the list_t to print
 *
 *
 * Return: the number of nodes
 */
size_t print_list(const list_t *head)
{
	size_t count = 0;

	while (h)
	{
		if (!h->str)
			printf("[0] (nil)\n");
		else
			printf("[%u] %s\n", h->len, h->str);
		h = h->next;
		count++;
	}
	return (count);
}
