#include "sort.h"


/**
 * lomuto_partition - Implements the Lomuto partition scheme for Quick Sort
 * @array: The array to be partitioned
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Number of elements in the array
 * Return: Index of the pivot element after partitioning
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int i = low - 1;
    size_t k;

    for (size_t j = low; j <= high - 1; ++j)
    {
        if (array[j] < pivot)
        {
            ++i;
            swap(&array[i], &array[j]);
        }
    }

    swap(&array[i + 1], &array[high]);

    /* Adjust the loop bounds to include all occurrences of the pivot */
    for (k = i + 1; k <= high; ++k)
    {
        if (k > i + 1)
            printf(", ");
        printf("%d", array[k]);
    }
    printf("\n");

    return i + 1;
}


/**
 * quicksort - Implements the Quick Sort algorithm using Lomuto partition
 * @array: The array to be sorted
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Number of elements in the array
 */
void quicksort(int *array, int low, int high, size_t size)
{
    if (low < high)
    {
        int pi;
        pi = lomuto_partition(array, low, high, size);
        quicksort(array, low, pi - 1, size);
        quicksort(array, pi + 1, high, size);
    }
}


/**
 * quick_sort - Sorts an array of integers in ascending order using Quick sort
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size <= 1)
        return;

    quicksort(array, 0, size - 1, size);
}


/**
 * swap - Swaps two integers
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}