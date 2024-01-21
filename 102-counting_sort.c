#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order using Counting sort
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void counting_sort(int *array, size_t size)
{
    int max = 0;
    size_t i;
    int *counting_array, *output_array;

    if (size < 2)
        return;

    /* Find the maximum value in the array */
    for (i = 0; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }

    /* Create and initialize the counting array */
    counting_array = malloc((max + 1) * sizeof(int));
    if (!counting_array)
        return;

    for (i = 0; i <= (size_t)max; i++)
        counting_array[i] = 0;

    /* Populate the counting array with the occurrences of each element */
    for (i = 0; i < size; i++)
        counting_array[array[i]]++;

    /* Accumulate the counts in the counting array */
    for (i = 1; i <= (size_t)max; i++)
        counting_array[i] += counting_array[i - 1];

    /* Create the output array based on the counting array */
    output_array = malloc(size * sizeof(int));
    if (!output_array)
    {
        free(counting_array);
        return;
    }

    for (i = size - 1; i != (size_t)-1; i--)
    {
        counting_array[array[i]]--;
        output_array[counting_array[array[i]]] = array[i];
    }

    /* Copy the sorted elements back to the original array */
    for (i = 0; i < size; i++)
        array[i] = output_array[i];

    /* Print the counting array */
    print_array(counting_array, max + 1);

    /* Free allocated memory */
    free(counting_array);
    free(output_array);
}
