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
*swap - the positions of two elements into an array
*@array: array
*@item1: array element
*@item2: array element
*/
int less(int item1, int item2)
{
    if (item1 < item2)
        return 1;
    return 0;
}
/**
 * shell_sort - function that sorts an array of integers in ascending
 * order using the Shell sort algorithm, using the Knuth sequence
 * @size: size of the array
 * @array: list with numbers
 */
void shell_sort(int *array, size_t size)
{
 
    size_t gap = 0, i, j = 0;
 
    while (gap < size / 3)
    {
        gap = 3 * gap + 1;
    }
   
    while (gap >= 1)
    {
        for (i = gap; i < size; i++)
        {
            for (j = i; j >= gap && less(array[j], array[j-gap]); j -= gap)
                swap(array, j, j-gap);
        }
        print_array(array, size);
        gap /= 3;
    }
}
