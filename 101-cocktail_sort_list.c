#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in
 * ascending order using the Cocktail shaker sort algorithm.
 * @list: Double pointer to the head of the linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current;
	int swapped = 1;

	if (list == NULL || *list == NULL)
		return;

	current = *list;
	while (swapped == 1)
	{
		swapped = 0;
		while (current->next != NULL)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(list, current, current->next);
				print_list(*list);
				swapped = 1;
			}
			else
				current = current->next;
		}

		if (swapped == 0)
			break;

		swapped = 0;
		while (current->prev != NULL)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes(list, current->prev, current);
				print_list(*list);
				swapped = 1;
			}
			else
				current = current->prev;
		}
	}
}

/**
 * swap_nodes - Swaps 2 nodes in a doubly linked list.
 * @list: Double pointer to the head of the linked list.
 * @node1: Pointer to the first node to be swapped.
 * @node2: Pointer to the second node to be swapped.
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1->prev != NULL)
		node1->prev->next = node2;
	else
		*list = node2;

	if (node2->next != NULL)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;
}
