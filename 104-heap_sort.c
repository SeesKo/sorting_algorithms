#include "sort.h"

/**
 * heapify - Converts an array into a max heap.
 * @array: The array to be transformed
 * @size: Size of the array
 * @i: Index of the current root in the heap
 * @n: Size of the heap
 */
void heapify(int *array, size_t size, size_t i, size_t n)
{
    size_t largest = i;
    size_t left = 2 * i + 1;
    size_t right = 2 * i + 2;

    if (left < n && array[left] > array[largest])
        largest = left;

    if (right < n && array[right] > array[largest])
        largest = right;

    if (largest != i)
    {
        int temp = array[i];
        array[i] = array[largest];
        array[largest] = temp;

        print_array(array, size);
        heapify(array, size, largest, n);
    }
}

/**
 * heap_sort - Sorts an array of integers in ascending order using Heap sort
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void heap_sort(int *array, size_t size)
{
	size_t i;

    if (size < 2)
        return;

    /* Build the max heap */
    for (i = size / 2 - 1; i != (size_t)-1; i--)
        heapify(array, size, i, size);

    /* Extract elements from the heap one by one */
    for (i = size - 1; i > 0; i--)
    {
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;

        print_array(array, size);
        heapify(array, size, 0, i);
    }
}
