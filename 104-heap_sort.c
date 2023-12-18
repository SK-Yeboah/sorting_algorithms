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
 * heapify - Converts an array into a max heap
 * @array: The array to be converted into a heap
 * @size: Number of elements in the array
 * @index: Index of the root of the current subtree
 */
void heapify(int *array, size_t size, size_t index)
{
    size_t largest = index;
    size_t left = 2 * index + 1;
    size_t right = 2 * index + 2;

    if (left < size && array[left] > array[largest])
        largest = left;

    if (right < size && array[right] > array[largest])
        largest = right;

    if (largest != index)
    {
        swap(&array[index], &array[largest]);
        print_array(array, size);
        heapify(array, size, largest);
    }
}

/**
 * heap_sort - Sorts an array of integers in ascending order
 *             using the Heap sort algorithm.
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void heap_sort(int *array, size_t size)
{
    int i;
    if (array == NULL || size <= 1)
        return;

    /* Build max heap */
    for (i = size / 2 - 1; i >= 0; i--)
        heapify(array, size, i);

    /* Extract elements from the heap one by one */
    for (i = size - 1; i > 0; i--)
    {
        swap(&array[0], &array[i]);
        print_array(array, size);
        heapify(array, i, 0);
    }
}