#include "lists.h"

/**
 * listint_len -It returns the number of elements in a linked lists
 * @head: linked list of type listint_t to traverse
 *
 * Return:The number of nodes
 */

size_t listint_len(const listint_t *head)
{
	size_t count = 0;

	while (head)
	{
		count++;
		head = head->next;
	}
	return (count);
}

