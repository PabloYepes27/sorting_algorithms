#include "sort.h"
#include <stdio.h>

/**
* getMax - A utility function to get maximum value in arr[]
* @arr: array
* @n: size of the array
* Return: array
*/
int getMax(int arr[], int n)
{
	int i, mx = arr[0];

	for (i = 1; i < n; i++)
		if (arr[i] > mx)
			mx = arr[i];
	return (mx);
}

/**
* countSort - A function to do counting sort of arr[] according to
* the digit represented by exp.
* @arr: array
* @n: size of the array
* @exp: Do counting sort for every digit
*/
void countSort(int arr[], int n, int exp)
{
	int output[1024]; /* output array should be n(size) */
	int i, count[10] = {0};

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
	int exp, m = getMax(array, size);

	/*
	* Do counting sort for every digit. Note that instead
    * of passing digit number, exp is passed. exp is 10^i
    * where i is current digit number
	*/
	for (exp = 1; m / exp > 0; exp *= 10)
		countSort(array, size, exp);
}
