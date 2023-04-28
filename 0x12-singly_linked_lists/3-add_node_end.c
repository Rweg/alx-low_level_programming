#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node_end - adds a new node at the end
 * @head: pointer to the list_t list (double)
 * @str: string to put in the new_node
 *
 * Return: The address of the new element, or NULL if it has failed
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *n_node, *n_tail;

	if (str == NULL)
		return (NULL);

	n_node = malloc(sizeof(list_t));
	if (n_node == NULL)
		return (NULL);

	n_node->str = strdup(str);
	if (n_node->str == NULL)
	{
		free(n_node);
		return (NULL);
	}

	n_node->len = strlen(str);
	n_node->next = NULL;

	if (*head == NULL)
	{
		*head = n_node;
		return (n_node);
	}

	n_tail = *head;
	while (n_tail->next != NULL)
		n_tail = n_tail->next;

	n_tail->next = n_node;

	return (n_node);
}
