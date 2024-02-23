#include "sort.h"

/**
 * swap_n - swap nodes in a doubly linked list
 * @h: pointer to the head node
 * @n1: 1st node pointer
 * @n2: node to swap
 */

void swap_n(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;

	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort_list - sorts a doubly linked list
 * @list: pointer to the head
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *insert_n, *itert;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	for (itert = (*list)->next; itert != NULL; itert = temp)
	{
		temp = itert->next;
		insert_n = itert->prev;

		while (insert_n != NULL && itert->n < insert_n->n)
		{
			swap_n(list, &insert_n, itert);
			print_list((const listint_t *)*list);
		}
	}
}
