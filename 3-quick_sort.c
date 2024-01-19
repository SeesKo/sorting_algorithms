#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in
 * ascending order using Quick sort algorithm.
 * @array: The array to be sorted.
 * @size: Number of elements in the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursion(array, 0, size - 1, size);
}

/**
 * quick_sort_recursion - Recursive helper function for Quick sort.
 * @array: The array to be sorted.
 * @low: Starting index of the partition to be sorted.
 * @high: Ending index of the partition to be sorted.
 * @size: Number of elements in the array.
 */
void quick_sort_recursion(int *array, int low, int high, size_t size)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = lomuto_partition(array, low, high, size);
		quick_sort_recursion(array, low, pivot_index - 1, size);
		quick_sort_recursion(array, pivot_index + 1, high, size);
	}
}

/**
 * lomuto_partition - Lomuto partition scheme for Quick sort.
 * @array: The array to be partitioned.
 * @low: Starting index of the partition.
 * @high: Ending index of the partition.
 * @size: Number of elements in the array.
 * Return: Index of the pivot element.
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int i, j, pivot, temp;

	i = low - 1;
	pivot = array[high];

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}

	if ((i + 1) != high)
	{
		temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;
		print_array(array, size);
	}

	return (i + 1);
}
