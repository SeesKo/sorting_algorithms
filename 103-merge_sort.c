#include "sort.h"

/**
 * merge_subarrays - Merges 2 sorted subarrays into one.
 * @array: The array to be merged.
 * @l: Index of the left subarray.
 * @m: Index of the middle point.
 * @r: Index of the right subarray.
 * @temp_array: Temporary array for merging.
 */
void merge_subarrays(int *array, size_t l, size_t m, size_t r,
		int *temp_array)
{
	size_t i = l, j = m + 1, k = 0;

	while (i <= m && j <= r)
		temp_array[k++] = (array[i] <= array[j]) ? array[i++] : array[j++];

	while (i <= m)
		temp_array[k++] = array[i++];

	while (j <= r)
		temp_array[k++] = array[j++];

	for (i = 0; i < k; i++)
		array[l + i] = temp_array[i];
}

/**
 * merge - Merges two subarrays of an array.
 * @array: The array to be merged.
 * @l: Index of the left subarray.
 * @m: Index of the middle point.
 * @r: Index of the right subarray.
 */
void merge(int *array, size_t l, size_t m, size_t r)
{
	size_t n1 = m - l + 1;
	size_t n2 = r - m;
	int *temp_array;

	printf("Merging...\n[left]: ");
	print_array(array + l, n1);
	printf("[right]: ");
	print_array(array + m + 1, n2);

	/* Creating a single temporary array to hold */
	/* both left and right subarrays */
	temp_array = malloc((n1 + n2) * sizeof(int));

	if (temp_array == NULL)
		exit(EXIT_FAILURE);

	merge_subarrays(array, l, m, r, temp_array);

	/* Printing the merged result */
	printf("[Done]: ");
	print_array(array + l, n1 + n2);

	/* Freeing the temporary array */
	free(temp_array);
}

/**
 * merge_sort_recursive - Recursive function that
 * performs the Merge Sort.
 * @array: The array to be sorted.
 * @l: Index of the leftmost element.
 * @r: Index of the rightmost element.
 */
void merge_sort_recursive(int *array, size_t l, size_t r)
{
	if (l < r)
	{
		/* Similar to (l+r)/2, but avoids overflow */
		/* for large l and r */
		size_t m = l + (r - l) / 2;

		/* Sorting the 1st and 2nd halves */
		merge_sort_recursive(array, l, m);
		merge_sort_recursive(array, m + 1, r);

		/* Merging the sorted halves */
		merge(array, l, m, r);
	}
}

/**
 * merge_sort - Sorts an array of integers in ascending
 * order using the Merge sort algorithm.
 * @array: The array to be sorted.
 * @size: Number of elements in the array.
 */
void merge_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	/* Starting the recursive sorting process */
	merge_sort_recursive(array, 0, size - 1);
}
