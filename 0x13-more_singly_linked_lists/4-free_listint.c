#include "lists.h"

/**
 * free_listint - Frees a linked list
 * @head: Head of the linked list
 *
 */

void free_listint(listint_t *head)
{
	listint_t *current;

	while (head != NULL)
	{
		current = head;
		head = head->next;
		free(current);
	}
}
