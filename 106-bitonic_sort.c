#include "sort.h"

/**
 * bitonic_sort - Sorts an array of integers in ascending
 * order using the Bitonic sort algorithm.
 * @array: The array to be sorted.
 * @size: Number of elements in @array.
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	printf("Merging [%lu/%lu] (UP):\n", size, size);
	print_array(array, size);

	bitonic_recursive(array, size, 1);

	printf("\nResult [%lu/%lu] (UP):\n", size, size);
	print_array(array, size);
}

/**
 * bitonic_recursive - Recursive helper function for
 * the Bitonic sort algorithm.
 * @array: The array to be sorted.
 * @size: Number of elements in @array.
 * @dir: Sorting direction (1 for ascending,
 * 0 for descending).
 */
void bitonic_recursive(int *array, size_t size, int dir)
{
	if (size > 1)
	{
		size_t mid = size / 2;

		printf("Merging [%lu/%lu] (%s):\n", mid, size, (dir == 1) ? "UP" : "DOWN");
		print_array(array, size);

		bitonic_recursive(array, mid, 1);
		bitonic_recursive(array + mid, mid, 0);

		bitonic_merge(array, size, dir);

		printf("\nResult [%lu/%lu] (%s):\n", mid, size, (dir == 1) ? "UP" : "DOWN");
		print_array(array, size);
	}
}

/**
 * bitonic_merge - Merges 2 bitonic sequences
 * in the given direction.
 * @array: The array to be sorted.
 * @size: Number of elements in @array.
 * @dir: Sorting direction (1 for ascending, 0 for descending).
 */
void bitonic_merge(int *array, size_t size, int dir)
{
	if (size > 1)
	{
		size_t step = size / 2;
		size_t i;

		for (i = 0; i < size - step; ++i)
		{
			if ((array[i] > array[i + step]) == dir)
				swap(&array[i], &array[i + step]);
		}

		bitonic_merge(array, step, dir);
		bitonic_merge(array + step, step, dir);
	}
}

/**
 * swap - Swaps 2 integers in an array.
 * @a: Pointer to the 1st integer.
 * @b: Pointer to the 2nd integer.
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
