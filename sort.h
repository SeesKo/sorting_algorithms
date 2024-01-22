#ifndef SORT_H
#define SORT_H

/* STANDARD LIBRARY HEADERS */
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>


/* STRUCTS */
/**
 * struct listint_s - Doubly linked list node.
 *
 * @n: Integer stored in the node.
 * @prev: Pointer to the previous element of the list.
 * @next: Pointer to the next element of the list.
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;


/* USER-DEFINED PROTOTYPES */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void quick_sort_recursion(int *array, int low, int high, size_t size);
int lomuto_partition(int *array, int low, int high, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void swapNode(listint_t **list, listint_t *node1, listint_t *node2);
void counting_sort(int *array, size_t size);
void merge(int *array, size_t l, size_t m, size_t r);
void merge_sort_recursive(int *array, size_t l, size_t r);
void merge_sort(int *array, size_t size);
void merge_subarrays(int *array, size_t l, size_t m, size_t r,
		int *temp_array);
void make_heap(int *array, size_t size, size_t i, size_t n);
void heap_sort(int *array, size_t size);
int getting_max(int *array, size_t size);
void countSort(int *array, size_t size, int exponent);
void radix_sort(int *array, size_t size);
void swap(int *a, int *b);
int hoare_partition(int *array, int low, int high, size_t size);
void quicksort(int *array, int low, int high, size_t size);
void quick_sort_hoare(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void bitonic_recursive(int *array, size_t size, int dir);
void bitonic_merge(int *array, size_t size, int dir);

#endif /* SORT_H */
