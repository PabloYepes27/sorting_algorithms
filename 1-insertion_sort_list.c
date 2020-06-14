#include "sort.h"
/**
 * insertion_sort_list - function that sorts a doubly linked list
 * of integers in ascending order using the Insertion sort algorithm
 * @list: Dobule linked list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node;

	node = (*list)->next;

	if (list == NULL || (*list)->next == NULL)
		return;
	while (node)
	{
		while (node->prev)
		{
			if (node->prev->n < node->n)
				break;
			node = swap_node(node, list);
			print_list(*list);
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
	listint_t *back = node->prev, *noderent = node;

	if (back->prev)
		back->prev->next = noderent;
	else
		*list = noderent;
	if (noderent->next)
		noderent->next->prev = back;
	back->next = noderent->next;
	noderent->prev = back->prev;
	noderent->next = back;
	back->prev = noderent;

	return (noderent);
}
