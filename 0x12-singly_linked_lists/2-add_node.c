#include "lists.h"
#include <stdlib.h>
#include <string.h>


/**
 * add_node - adds a new node at the beginning of a list_t list
 * @head:is a pointer to a pointer to the first node of the list
 * @str: string to be added as the str member of the new node
 *
 * Return: address of the new element, or NULL if it has failed
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new_node;

	if (!head || !str)
		return (NULL);

	new_node = malloc(sizeof(list_t));
	if (!new_node)
		return (NULL);

	new_node->str = strdup(str);
	if (!new_node->str)
	{
		free(new_node);
		return (NULL);
	}

	new_node->len = strlen(str);
	new_node->next = *head;
	*head = new_node;

	return (new_node);
}
