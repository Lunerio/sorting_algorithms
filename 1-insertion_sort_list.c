#include "sort.h"

/**
 * insertion_sort_list - sort a list with insertion
 * @list: list to sort
 */

void insertion_sort_list(listint_t **list)
{
	listint_t  *act = NULL, *tmp = NULL;

	if (list == NULL || (*list)->next == NULL)
		return;

	tmp = *list;

	while (tmp->next)
	{
		act = tmp;

		while (act->n > act->next->n && act->next != NULL)
		{
			act = act->next;
			while (act->prev != NULL && act->n < act->prev->n)
			{
				insert_nodes(&act, list);

				print_list(*list);
			}
		}

		if (tmp->next != NULL)
		{
			tmp = act->next;
		}
		else
			break;
	}
}

/**
 * insert_nodes - swap nodes
 * @act: actual
 * @list: pointer to head
 */

void insert_nodes(listint_t **act, listint_t **list)
{
	(*act)->prev->next = (*act)->next;

	if ((*act)->next != NULL)
		(*act)->next->prev = (*act)->prev;

	(*act)->next = (*act)->prev;
	(*act)->prev = (*act)->prev->prev;

	if ((*act)->prev != NULL)
		(*act)->prev->next = *act;
	else
		*list = *act;

	(*act)->next->prev = *act;
}
