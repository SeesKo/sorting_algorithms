#include "sort.h"

/**
 * swap - Swaps two integers in an array.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - Lomuto partition scheme for Quick sort.
 * @array: Array to be sorted.
 * @low: First index of the partition.
 * @high: Last index of the partition.
 * @size: Size of the array.
 *
 * Return: Index of the pivot element after partitioning.
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int i, j, pivot;

	i = low - 1;
	pivot = array[high];

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
	}

	swap(&array[i + 1], &array[high]);
	print_array(array, size);

	return (i + 1);
}

/**
 * quick_sort_recursive - Recursive function to perform Quick sort.
 *
 * @array: The array to be sorted.
 * @low: First index of the partition to be sorted.
 * @high: Last index of the partition to be sorted.
 * @size: Number of elements in the array.
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		/* Partition the array and get the pivot index */
		pivot = lomuto_partition(array, low, high, size);

		/* Recursively sort the sub-arrays on both sides of the pivot */
		quick_sort_recursive(array, low, pivot - 1, size);
		quick_sort_recursive(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in
 * ascending order using Quick sort.
 * @array: Array to be sorted.
 * @size: Size of the array.
 */
void quick_sort(int *array, size_t size)
{
	/* Nothing to sort */
	if (array == NULL || size <= 1)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}
