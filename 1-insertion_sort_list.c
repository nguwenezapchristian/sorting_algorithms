#include "sort.h"

/**
 * insertion_sort_list - insertion sort algorithm
 * @list: head pointer
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	/**
	 * it took me some time to figure this out
	 * when i tried to do. but it works
	 * we's get time to explain it later
	 */
	listint_t *curr;
	listint_t *temp;

	if (list == NULL || (*list)->next == NULL)
		return;
	curr = (*list)->next;
	while (curr != NULL)
	{
		temp = curr->prev;
		while (temp != NULL && temp->n > curr->n)
		{
			if (temp->prev != NULL)
				temp->prev->next = curr;
			else
				*list = curr;
			curr->prev = temp->prev;
			temp->prev = curr;
			temp->next = curr->next;

			if (curr->next != NULL)
				curr->next->prev = temp;

			curr->next = temp;
			print_list(*list);
			temp = curr->prev;
		}
		curr = curr->next;
	}
}
