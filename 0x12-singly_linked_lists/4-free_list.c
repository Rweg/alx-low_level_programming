#include <stdlib.h>
#include "lists.h"


/**
 * free_list - frees a linked list_t list
 * @head:Is a pointer to the head of the list
 */
void free_list(list_t *head)
{
	list_t *tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp->str);
		free(tmp);
	}
}
