#include "sort.h"

/**
 * swap - Swaps two elements in an array
 * @a: Pointer to the first element
 * @b: Pointer to the second element
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * hoare_partition - Hoare partition scheme for Quick Sort
 * @array: Array to be partitioned
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Size of the array
 * Return: Index of the pivot after partitioning
 */
int hoare_partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int i = low - 1, j = high + 1;

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
        {
            return j;
        }
    }
}

/**
 * quicksort - Recursive function to perform Quick Sort using Hoare scheme
 * @array: Array to be sorted
 * @low: Starting index of the array or partition
 * @high: Ending index of the array or partition
 * @size: Size of the array
 */
void quicksort(int *array, int low, int high, size_t size)
{
    if (low < high)
    {
        int pivot_index = hoare_partition(array, low, high, size);

        if (pivot_index - 1 - low > 0)
            quicksort(array, low, pivot_index - 1, size);

        if (high - pivot_index - 1 > 0)
            quicksort(array, pivot_index + 1, high, size);
    }
}

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order using Quick sort
 * @array: Array to be sorted
 * @size: Size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quicksort(array, 0, size - 1, size);
}

