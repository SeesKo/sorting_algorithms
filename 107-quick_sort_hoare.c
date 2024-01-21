#include "sort.h"

/**
 * swap - Swaps 2 elements in an array.
 * @a: Pointer to the 1st element.
 * @b: Pointer to the 2nd element.
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * hoare_partition - Hoare partition scheme for Quick Sort.
 * @array: Array to be partitioned.
 * @low: First index of the partition.
 * @high: Last index of the partition.
 * @size: Size of the array.
 * Return: Index of the pivot after partitioning.
 */
int hoare_partition(int *array, int low, int high, size_t size)
{
	int pivot, i, j;

	pivot = array[high];
	i = low - 1;
	j = high + 1;

	while (1)
	{
		do {
			i++;
		} while (i <= high && array[i] < pivot);

		do {
			j--;
		} while (j >= low && array[j] > pivot);

		if (i < j)
		{
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
		else
			return (j);
	}
}

/**
 * quicksort - Recursive function to perform
 * Quick Sort using Hoare scheme.
 * @array: Array to be sorted.
 * @low: First index of the array or partition.
 * @high: Last index of the array or partition.
 * @size: Size of the array.
 */
void quicksort(int *array, int low, int high, size_t size)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = hoare_partition(array, low, high, size);

		if (pivot_index - 1 - low > 0)
			quicksort(array, low, pivot_index - 1, size);

		if (high - pivot_index - 1 > 0)
			quicksort(array, pivot_index + 1, high, size);
	}
}

/**
 * quick_sort_hoare - Sorts an array of integers in
 * ascending order using the Quick sort algorithm.
 * @array: Array to be sorted.
 * @size: Size of the array.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort(array, 0, size - 1, size);
}
