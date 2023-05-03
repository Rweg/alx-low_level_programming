#include "lists.h"

/**
 * free_listint_safe - frees a linked list
 * @h: pointer to the first node in the linked list
 *
 * Return: number of elements in the freed list
 */

size_t free_listint_safe(listint_t **h)
{
	size_t len = 0;
	listint_t *tmp, *current, *prev;

	if (!h || !*h)
        return (0);

	current = *h;
	while (current)
	{
		if (current > current->next)
		{
			tmp = current->next;
			while (tmp && tmp > current)
			{
				prev = tmp;
				tmp = tmp->next;
				free(prev);
				len++;
			}
			free(current);
			len++;

           *h = NULL;
            return (len);
        }
		tmp = current;
		current = current->next;
		free(tmp);
		len++;
	}

	*h = NULL;

	return (len);
}
