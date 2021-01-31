#include "sort.h"

void insertion_sort_list(listint_t **list)
{
    listint_t *i = NULL;
    listint_t *j = (*list)->next;
    listint_t *tmp = j;

    if (list == NULL || (*list)->next == NULL)
	return;

    while (tmp)
    {
	i = tmp->prev;
	while ((i->prev != NULL) && (i->prev->n > j->n))
	{
	    i = i->prev;
	}
	if ((j->n) < (i->n))
	{
	    if (tmp->next == NULL) /*si movemos el ultimo*/
	    {
		j->prev->next = NULL;
		if (i->prev == NULL) /*si tenemos que mover antes del primero*/
		{
		    i->prev = j;
		    j->prev = NULL;
		    j->next = i;
		    *list = j;
		    print_list(*list);
		}
		else /*si movemos al medio*/
		{
		    j->prev = i->prev;
		    j->next = i;
		    i->prev = j;
		    j->prev->next = j;
		    print_list(*list);
		}
	    }
	    else /*si movemos algo del medio*/
	    {
		tmp = j->next;
		if (i->prev == NULL) /*si tenemos que mover antes del primero*/
		{
		    j->prev->next = j->next;
		    j->next->prev = j->prev;
		    i->prev = j;
		    j->prev = NULL;
		    j->next = i;
		    *list = j;
		    print_list(*list);
		}
		else /*si movemos al medio*/
		{
		    j->prev->next = j->next;
		    j->next->prev = j->prev;
		    j->next = i;
		    j->prev = i->prev;
		    j->prev->next = j;
		    i->prev = j;
		    print_list(*list);
		}
	    }
	}
	tmp = j->next;
	j = tmp;
    }
}
