#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list using Cocktail Shaker Sort
 * @list: Double pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
    listint_t *current;
    int swapped = 1;

    if (list == NULL || *list == NULL)
        return;

    while (swapped)
    {
        swapped = 0;

        /* Forward pass (left to right) */
        for (current = *list; current->next != NULL; current = current->next)
        {
            if (current->n > current->next->n)
            {
                swap_nodes(list, current, current->next);
                swapped = 1;
                print_list(*list);
            }
        }

        if (!swapped)
            break;

        swapped = 0;

        /* Backward pass (right to left) */
        for (; current->prev != NULL; current = current->prev)
        {
            if (current->n < current->prev->n)
            {
                swap_nodes(list, current->prev, current);
                swapped = 1;
                print_list(*list);
            }
        }
    }
}

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Double pointer to the head of the list
 * @node1: First node to be swapped
 * @node2: Second node to be swapped
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
