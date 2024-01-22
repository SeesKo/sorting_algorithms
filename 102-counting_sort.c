#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending
 * order using the Counting sort algorithm.
 * @array: The array to be sorted.
 * @size: Number of elements in the array.
 */
void counting_sort(int *array, size_t size)
{
	int max, *counting_array, j, index;
	size_t i;

	if (array == NULL || size < 2)
		return;

	/* Finding the maximum value in the array */
	max = array[0];
	for (i = 1; i < size; ++i)
	{
		if (array[i] > max)
			max = array[i];
	}
	/* Creating and initialize the counting array */
	counting_array = malloc((max + 1) * sizeof(int));
	if (counting_array == NULL)
		return;

	for (j = 0; j <= max; ++j)
		counting_array[j] = 0;
	/* Counting occurrences of each element in the array */
	for (i = 0; i < size; ++i)
		counting_array[array[i]]++;

	/* Printing the counting array */
	print_array(counting_array, max + 1);

	/* Updating the array with sorted values */
	index = 0;
	for (j = 0; j <= max; ++j)
	{
		while (counting_array[j] > 0)
		{
			array[index++] = j;
			counting_array[j]--;
		}
	}
	/* Freeing dynamically allocated memory */
	free(counting_array);
}
