#include "sort.h"
#include <stdio.h>
/**
 *_calloc - this is a calloc function
 *@nmemb: number of elemets
 *@size: bit size of each element
 *Return: pointer to memory assignement
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int i = 0;
	char *p;

	if (nmemb == 0 || size == 0)
		return ('\0');
	p = malloc(nmemb * size);
	if (p == '\0')
		return ('\0');
	for (i = 0; i < (nmemb * size); i++)
		p[i] = '\0';
	return (p);
}
/**
* getMax - A utility function to get maximum value in arr[]
* @arr: array
* @n: size of the array
* Return: array
*/
int getMax(int arr[], int n)
{
	int i, max = arr[0];

	for (i = 1; i < n; i++)
		if (arr[i] > max)
			max = arr[i];
	return (max);
}

/**
* countSort - A function to do counting sort of arr[] according to
* the digit represented by exp.
* @arr: array
* @n: size of the array
* @exp: exp is 10^i
*/
void countSort(int arr[], int n, int exp)
{
	int *output = '\0'; /* output array should be n(size) */
	int i, count[10] = {0};

	output = _calloc(n + 1, sizeof(int));
	/* Store count of occurrences in count[] */
	for (i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;

	/*
	* Change count[i] so that count[i] now contains actual
    * position of this digit in output[]
	*/
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	/* Build the output array */
	for (i = n - 1; i >= 0; i--)
	{
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	/*
	* Copy the output array to arr[], so that arr[] now
    * contains sorted numbers according to current digit
	*/
	for (i = 0; i < n; i++)
		arr[i] = output[i];
	print_array(arr, n);
	free(output);
}

/**
* radix_sort - The main function to that sorts arr[]
* of size n using Radix Sort
* @array: array
* @size: size of the array
*/
void radix_sort(int *array, size_t size)
{
	/* Find the maximum number to know number of digits */
	int exp, maximum = getMax(array, size);

	if (array == '\0' || size < 2)
		return;
	/*
	* Do counting sort for every digit. Note that instead
    * of passing digit number, exp is passed. exp is 10^i
    * where i is current digit number
	*/
	for (exp = 1; maximum / exp > 0; exp *= 10)
		countSort(array, size, exp);
}
