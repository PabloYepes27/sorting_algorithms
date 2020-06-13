#include "sort.h"
/**
 * selection_sort - function that sorts an array of integers in ascending
 * order using the Selection sort algorithm
 * @size: size of the array
 * @array: list with numbers
 */
void selection_sort(int *array, size_t size)
{
	size_t i, index;
	int tmp, swap;

	if (array == NULL)
		return;
	for (i = 0; i < size; i++)
	{
		tmp = i;
		for (index = i + 1; index < size; index++)
		{
			if (array[tmp] > array[index])
				tmp = index;
		}
		swap = array[i];
		array[i] = array[tmp];
		array[tmp] = swap;
		print_array(array, size);
	}
}