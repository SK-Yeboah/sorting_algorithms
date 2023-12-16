#include "sort.h"


/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Pointer to a pointer to the head of the list
 * @node1: Pointer to the first node
 * @node2: Pointer to the second node
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
    if (node1->prev != NULL)
        node1->prev->next = node2;

    if (node2->next != NULL)
        node2->next->prev = node1;

    node1->next = node2->next;
    node2->prev = node1->prev;

    node1->prev = node2;
    node2->next = node1;

    if (node2->prev == NULL)
        *list = node2;
}

/**
 * insertion_sort_list -  Sorts a doubly linked list of integers in ascending order
 *                       using the Insertion sort algorithm
 *@list: Pointer to a pointer to the head of the list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev, *temp;

	if(list == NULL || *list == NULL || (*list)->next ==NULL)
	{
		return;
	}

	current =(*list)->next;

	while(current != NULL)
	{
		temp = current;
		prev =current->prev;
		
		while (prev != NULL && prev->n > temp->n)
		{
			swap_nodes(list, prev, temp);
			print_list(*list);
			prev = temp->prev;
		}
		current = current->next;
		

	}
}


