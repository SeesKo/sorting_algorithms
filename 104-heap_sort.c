#include "sort.h"

/**
 * make_heap - Converts an array into a max heap.
 * @array: The array to be converted.
 * @size: Size of the array.
 * @i: Index of the current root in the heap.
 * @n: Size of the heap.
 */
void make_heap(int *array, size_t size, size_t i, size_t n)
{
	size_t largest, left, right;
	int temp;

	largest = i;
	left = 2 * i + 1;
	right = 2 * i + 2;

	if (left < n && array[left] > array[largest])
		largest = left;

	if (right < n && array[right] > array[largest])
		largest = right;

	if (largest != i)
	{
		temp = array[i];
		array[i] = array[largest];
		array[largest] = temp;

		print_array(array, size);
		make_heap(array, size, largest, n);
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order
 * using the Heap sort algorithm.
 * @array: The array to be sorted.
 * @size: Number of elements in the array.
 */
void heap_sort(int *array, size_t size)
{
	size_t i;
	int temp;

	if (size < 2)
		return;

	/* Building the max heap */
	for (i = size / 2 - 1; i != (size_t)-1; i--)
		make_heap(array, size, i, size);

	/* Extracting elements from the heap one by one */
	for (i = size - 1; i > 0; i--)
	{
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;

		print_array(array, size);
		make_heap(array, size, 0, i);
	}
}
