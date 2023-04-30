#include "lists.h"

/**
 * add_nodeint - Add a new node at the beginning of a listint_t list
 * @head: Pointer to pointer to the first node of the list
 * @n: Value of the new node
 *
 * Return: Pointer to the new node, or NULL if it fails
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new_node;

	if (!head)
		return (NULL);

	new_node = malloc(sizeof(listint_t));
	if (!new_node)
		return (NULL);

	new_node->n = n;
	new_node->next = *head;
	*head = new_node;

	return (new_node);
}

