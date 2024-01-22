#include "sort.h"

/**
 * counting_sort - Sorts an array of integers using counting sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void counting_sort(int *array, size_t size)
{
    int max;
    int *counting_array;
    size_t i, j;

    if (array == NULL || size < 2)
        return;

    /* Find the maximum value in the array */
    max = array[0];
    for (i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }

    /* Create and initialize the counting array */
    counting_array = malloc((max + 1) * sizeof(int));
    if (counting_array == NULL)
        return;

    for (i = 0; i <= (size_t)max; i++)
        counting_array[i] = 0;

    /* Populate the counting array with the count of each element */
    for (i = 0; i < size; i++)
        counting_array[array[i]]++;

    /* Print the counting array */
    print_array(counting_array, max + 1);

    /* Update the original array with sorted values */
    for (i = 0, j = 0; j <= (size_t)max; j++)
    {
        while (counting_array[j] > 0)
        {
            array[i++] = (int)j;
            counting_array[j]--;
        }
    }

    /* Free the counting array */
    free(counting_array);
}

