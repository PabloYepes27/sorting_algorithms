#include "sort.h"
/**
*swap - the positions of two elements into an array
*@array: array
*@item1: array element
*@item2: array element
*/
void swap(int *array, int item1, int item2)
{
	int tmp;

	tmp = array[item1];
	array[item1] = array[item2];
	array[item2] = tmp;
}
/**
 *lomuto_partition - lomuto partition sorting scheme implementation
 *@array: array
 *@first: first array element
 *@last: last array element
 *@size: size array
 *Return: return the position of the last element sorted
 */
int lomuto_partition(int *array, int first, int last, int size)
{
	int pivot, current, finder, flag = 0;

	pivot = array[last];
	current = first - 1;

	for (finder = first; finder <= last - 1; finder++)
	{
		if (array[finder] <= pivot)
		{
			current++;
			swap(array, current, finder);
		}
	}
	if (current != first - 1)
	{
		print_array(array, size);
		flag = 1;
	}
	swap(array, current + 1, last);
	if (flag == 0)
		print_array(array, size);
	return (current + 1);
}
/**
 *qs - qucksort algorithm implementation
 *@array: array
 *@first: first array element
 *@last: last array element
 *@size: array size
 */
void qs(int *array, int first, int last, int size)
{
	int position;


	if (first < last)
	{
		position = lomuto_partition(array, first, last, size);

		qs(array, first, position - 1, size);
		qs(array, position + 1, last, size);

	}
}
/**
 *quick_sort - prepare the terrain to quicksort algorithm
 *@array: array
 *@size: array size
 */
void quick_sort(int *array, size_t size)
{
	qs(array, 0, size - 1, size);
	print_array(array, size);
}
