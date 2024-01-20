#include "sort.h"

/**
 * getting_max - Gets the maximum value in an array.
 * @array: The array to find the maximum value.
 * @size: Size of the array.
 * Return: The maximum value in the array.
 */
int getting_max(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}

/**
 * countSort - Performs 'Counting Sort'
 * based on significant digit.
 * @array: The array to be sorted.
 * @size: Size of the array.
 * @exponent: The significant digit to consider.
 */
void countSort(int *array, size_t size, int exponent)
{
	int *output, *count;
	size_t i;

	output = malloc(sizeof(int) * size);
	count = malloc(sizeof(int) * 10);

	if (output == NULL || count == NULL)
	{
		free(output);
		free(count);
		return;
	}

	for (i = 0; i < 10; i++)
		count[i] = 0;

	for (i = 0; i < size; i++)
		count[(array[i] / exponent) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; (ssize_t)i >= 0; i--)
	{
		output[count[(array[i] / exponent) % 10] - 1] = array[i];
		count[(array[i] / exponent) % 10]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];

	print_array(array, size);

	free(output);
	free(count);
}

/**
 * radix_sort - Sorts an array of integers in ascending
 * order using the Radix sort algorithm.
 * @array: The array to be sorted.
 * @size: Number of elements in the array.
 */
void radix_sort(int *array, size_t size)
{
	int max, exponent;

	if (size < 2)
		return;

	max = getting_max(array, size);

	for (exponent = 1; max / exponent > 0; exponent *= 10)
		countSort(array, size, exponent);
}
