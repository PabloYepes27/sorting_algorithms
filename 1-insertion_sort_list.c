#include "sort.h"
#include <stdio.h>
/**
 * insertion_sort_list - function that sorts a doubly linked list
 * of integers in ascending order using the Insertion sort algorithm
 * @list: Dobule linked list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *aux, *node = (*list)->next;

	while (node)
	{
		if (node->n < node->prev->n)
		{
			node = swap_node(node, list);
			aux = node;
			while (aux->prev)
			{
				if (aux->n > aux->next->n)
					break;
				aux = swap_node(aux, list);
				print_list(*list);
			}
		}
		node = node->next;
	}
}
/**
 *swap_node - swap a node for his previous one
 *@node: node
 *@list: node list
 *Return: return a pointer to a node which was enter it
 */
listint_t *swap_node(listint_t *node, listint_t **list)
{
	listint_t *back = node->prev, *current = node;

	if (back->prev)
		back->prev->next = current;
	else
		*list = current;
	if (current->next)
		current->next->prev = back;
	back->next = current->next;
	current->prev = back->prev;
	current->next = back;
	back->prev = current;

	return (current);
