#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of
 * integers in ascending order using Insertion sort.
 *
 * @list: Pointer to the head of the list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *prev, *current, *next;

	if (list == NULL || *list == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		next = current->next;

		while (current->prev != NULL && current->n < current->prev->n)
		{
			prev = current->prev;

			/* Swapping nodes */
			current->prev = prev->prev;
			prev->next = current->next;

			if (current->next != NULL)
				current->next->prev = prev;

			current->next = prev;
			prev->prev = current;

			if (current->prev != NULL)
				current->prev->next = current;
			else
				*list = current;

			/* Printing list after each swap */
			print_list(*list);
		}

		current = next;
	}
}
