#include "sort.h"
/**
 * insertion_sort_list - sorts a double linked list in ascending order.
 * @list: pointer to first node of the linked list.
 *
 * Return: nothing.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *front;
	listint_t *back;
	listint_t *aux;

	if (!list || !*list || !(*list)->next)
		return;
	for (front = (*list)->next; front; front = aux)
	{
		aux = front->next;
		back = front->prev;
		while (back && front->n < back->n)
		{
			back->next = front->next;
			if (front->next)
				front->next->prev = back;
			front->prev = back->prev;
			front->next = back;
			if (back->prev)
				back->prev->next = front;
			else
				*list = front;
			back->prev = front;
			back = front->prev;
			print_list(*list);
		}
	}
}
