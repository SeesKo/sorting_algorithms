#include "sort.h"

/**
 * merge - Merge two subarrays of array[].
 * @array: The array to be merged.
 * @l: Index of the left subarray.
 * @m: Index of the middle point.
 * @r: Index of the right subarray.
 */
void merge(int *array, size_t l, size_t m, size_t r)
{
    size_t i, j, k;
    size_t n1 = m - l + 1;
    size_t n2 = r - m;
    int *left, *right;

    printf("Merging...\n[left]: ");
    print_array(array + l, n1);
    printf("[right]: ");
    print_array(array + m + 1, n2);

    /* Create temporary arrays */
    left = malloc(n1 * sizeof(int));
    right = malloc(n2 * sizeof(int));

    if (left == NULL || right == NULL)
	    exit(EXIT_FAILURE);

    /* Copy data to temporary arrays left[] and right[] */
    for (i = 0; i < n1; i++)
        left[i] = array[l + i];
    for (j = 0; j < n2; j++)
        right[j] = array[m + 1 + j];

    /* Merge the temporary arrays back into array[l..r] */
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            array[k] = left[i];
            i++;
        }
        else
        {
            array[k] = right[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of left[], if there are any */
    while (i < n1)
    {
        array[k] = left[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of right[], if there are any */
    while (j < n2)
    {
        array[k] = right[j];
        j++;
        k++;
    }

    /* Print the merged result */
    printf("[Done]: ");
    print_array(array + l, n1 + n2);

    /* Free the temporary arrays */
    free(left);
    free(right);
}

/**
 * merge_sort_recursive - Recursive function to perform Merge Sort.
 * @array: The array to be sorted.
 * @l: Index of the leftmost element.
 * @r: Index of the rightmost element.
 */
void merge_sort_recursive(int *array, size_t l, size_t r)
{
    if (l < r)
    {
        /* Same as (l+r)/2, but avoids overflow for large l and r */
        size_t m = l + (r - l) / 2;

        /* Sort first and second halves */
        merge_sort_recursive(array, l, m);
        merge_sort_recursive(array, m + 1, r);

        /* Merge the sorted halves */
        merge(array, l, m, r);
    }
}

/**
 * merge_sort - Sorts an array of integers in ascending order using Merge sort.
 * @array: The array to be sorted.
 * @size: Number of elements in the array.
 */
void merge_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    /* Start the recursive sorting process */
    merge_sort_recursive(array, 0, size - 1);
}
