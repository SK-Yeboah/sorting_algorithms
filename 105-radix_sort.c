#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * getMax - Returns the maximum element from an array
 * @array: The array to find the maximum from
 * @size: The size of the array
 * Return: The maximum element
 */
int getMax(int *array, size_t size)
{
    size_t i;
    int max = array[0];

    for (i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }

    return (max);
}

/**
 * countingSort - Sorts an array of integers based on a particular
 *                digit using counting sort
 * @array: The array to be sorted
 * @size: The size of the array
 * @exp: The current exponent representing the significant digit
 */
void countingSort(int *array, size_t size, int exp)
{
    const int base = 10;
    size_t i;
    int j;
    size_t k;

    int *output = malloc(size * sizeof(int));
    int *count = malloc(base * sizeof(int));

    if (output == NULL || count == NULL)
    {
        free(output);
        free(count);
        exit(EXIT_FAILURE);
    }


    for (i = 0; i <  (size_t)base; i++)
        count[i] = 0;

    for (i = 0; i < size; i++)
        count[(array[i] / exp) % base]++;

    for (i = 1; i <  (size_t)base; i++)
        count[i] += count[i - 1];

    for (j = size - 1; j >= 0; j--)
    {
        output[count[(array[j] / exp) % base] - 1] = array[j];
        count[(array[j] / exp) % base]--;
    }

    for (k = 0; k < size; k++)
        array[i] = output[k];

    print_array(array, size);
    free(output);
    free(count);
}
/**
 * radix_sort - Sorts an array of integers in ascending order
 *               using the LSD Radix sort algorithm.
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void radix_sort(int *array, size_t size)
{
    size_t i;
    int max;

    if (array == NULL || size <= 1)
        return;

    max = getMax(array, size);

    for (i = 1; max / i > 0; i *= 10)
        countingSort(array, size, i);
}