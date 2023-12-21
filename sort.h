#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;

void swap(int *a, int *b);
void bubble_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void print_list(const listint_t *list);
int lomuto_partition(int *array, int low, int high, size_t size);
void quicksort(int *array, int low, int high, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);

void merge_sort(int *array, size_t size);
void merge(int *array, size_t size, int *left, size_t left_size, int *right, size_t right_size);
void print_subarray(const int *array, size_t start, size_t end);

void heap_sort(int *array, size_t size);
void heapify(int *array, size_t size, size_t index);

void radix_sort(int *array, size_t size);
void countingSort(int *array, size_t size, int exp);
int getMax(int *array, size_t size);





#endif 
