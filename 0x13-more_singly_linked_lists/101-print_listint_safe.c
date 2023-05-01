#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * listint_len - returns the number of elements in a linked listint_t list.
 * @h: pointer to the beginning of the list
 *
 * Return: the number of nodes in the list
 */
size_t listint_len(const listint_t *h)
{
	size_t count = 0;

	while (h)
	{
		count++;
		h = h->next;
	}

	return (count);
}

/**
 * print_listint_safe - prints a listint_t linked list.
 * @head: pointer to the beginning of the list
 *
 * Return: the number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t count = 0, i;
	const listint_t *current, *loop_start;

	current = loop_start = head;
	while (current)
	{
		count++;
		printf("[%p] %d\n", (void *)current, current->n);
		current = current->next;
		if (current >= loop_start)
		{
			printf("-> [%p] %d\n", (void *)current, current->n);
			break;
		}
		loop_start = loop_start->next;
	}

	if (!current)
		exit(98);

	/* check for a loop */
	i = listint_len(head);
	if (count > i)
	{
		count = i;
		printf("-> [%p] %d\n", (void *)current, current->n);
	}

	return (count);
}
