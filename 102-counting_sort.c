#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order using Counting sort
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void counting_sort(int *array, size_t size)
{
    size_t i;
    int max, *counting_array, *output_array;

    if (size < 2)
        return;

    max = array[0];
    for (i = 1; i < size; i++)
        if (array[i] > max)
            max = array[i];

    counting_array = malloc((max + 1) * sizeof(int));
    if (!counting_array)
        return;

    output_array = malloc(size * sizeof(int));
    if (!output_array)
    {
        free(counting_array);
        return;
    }

    for (i = 0; i <= (size_t)max; i++)
        counting_array[i] = 0;
    for (i = 0; i < size; i++)
        counting_array[array[i]]++;
    for (i = 1; i <= (size_t)max; i++)
        counting_array[i] += counting_array[i - 1];
    for (i = size - 1; (size_t)i != (size_t)-1; i--)
    {
        counting_array[array[i]]--;
        output_array[counting_array[array[i]]] = array[i];
    }
    for (i = 0; i < size; i++)
        array[i] = output_array[i];

    print_array(counting_array, max + 1);

    free(counting_array);
    free(output_array);
}
