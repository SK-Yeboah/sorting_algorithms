#include "sort.h"


/**
 * bitonic_sort - Sorts an array of integers using the Bitonic Sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in the array (must be a power of 2)
 */
void bitonic_sort(int *array, size_t size)
{
    if (array == NULL || size < 2 || (size & (size - 1)) != 0)
        return;

    printf("\n");
    bitonic_recursive_sort(array, size, 1);
}

/**
 * bitonic_recursive_sort - Recursive helper function for Bitonic Sort
 * @array: The array to be sorted
 * @size: Number of elements in the array
 * @dir: Sorting direction (1 for ascending, 0 for descending)
 */
void bitonic_recursive_sort(int *array, size_t size, int dir)
{
    if (size > 1)
    {
        size_t mid = size / 2;
        printf("Merging [%lu/%lu] (%s):\n", size, size, dir ? "UP" : "DOWN");
        print_array(array, size);

        bitonic_recursive_sort(array, mid, 1);
        bitonic_recursive_sort(array + mid, mid, 0);

        bitonic_merge(array, size, dir);

        printf("Result [%lu/%lu] (%s):\n", size, size, dir ? "UP" : "DOWN");
        print_array(array, size);
    }
}

/**
 * bitonic_merge - Merges two halves of an array in a Bitonic manner
 * @array: The array to be merged
 * @size: Number of elements in the array
 * @dir: Sorting direction (1 for ascending, 0 for descending)
 */
void bitonic_merge(int *array, size_t size, int dir)
{
    if (size > 1)
    {
        size_t k = size / 2;
        size_t i;

        for (i = 0; i < k; ++i)
        {
            if ((array[i] > array[i + k]) == dir)
            {
                swap(&array[i], &array[i + k]);
                printf("Result [%lu/%lu] (%s):\n", size, size, dir ? "UP" : "DOWN");
                print_array(array, size);
            }
        }

        bitonic_merge(array, k, dir);
        bitonic_merge(array + k, k, dir);
    }
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

/**
 * print_array - Prints the elements of an array
 * @array: The array to be printed
 * @size: Number of elements in the array
 */
/*void print_array(const int *array, size_t size)
{
    size_t i;

    if (array == NULL)
        return;

    for (i = 0; i < size; ++i)
    {
        if (i > 0)
            printf(", ");
        printf("%d", array[i]);
    }
    printf("\n");
}*/
