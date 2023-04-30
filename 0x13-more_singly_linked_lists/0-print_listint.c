#include "lists.h"

/**
 * print_listint -It prints all the elements of the listint_t list
 * @head: A pointer to the head of the list
 *
 * Return: Returns the number of nodes
 */
size_t print_listint(const listint_t *head)
{
	size_t count = 0;

	while (head != NULL)
	{
		printf("%d\n", head->node);
		head = head->next;
		count++;
	}

	return (count);
}
