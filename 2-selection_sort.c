#include "sort.h"

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
 * selection_sort - Sorts an array of integers in ascending order using
 *                  the Selection sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
/*void selection_sort(int *array, size_t size)
{
    size_t i;
    size_t j;
    size_t k;

    if (array == NULL || size <= 1)
        return;

    for (i = 0; i < size - 1; ++i)
    {
        size_t min_index = i;

        for (j = i + 1; j < size; ++j)
        {
            if (array[j] < array[min_index])
                min_index = j;
        }

        if (min_index != i)
        {
            swap(&array[i], &array[min_index]);

           
            for (k = 0; k < size; ++k)
            {
                if (k > 0)
                    printf(", ");
                printf("%d", array[k]);
            }
            printf("\n");
        }
    }
}*/


/**
 * selection_sort - Sorts an array of integers in ascending order using
 *                  the Selection sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in the array
 * @print_flag: Flag to indicate whether to print the array after each swap
 */
void selection_sort(int *array, size_t size, int print_flag)
{
    if (array == NULL || size <= 1)
        return;

    size_t i, j, k;

    for (i = 0; i < size - 1; ++i)
    {
        size_t min_index = i;

        for (j = i + 1; j < size; ++j)
        {
            if (array[j] < array[min_index])
                min_index = j;
        }

        if (min_index != i)
        {
            swap(&array[i], &array[min_index]);

            /* Print the array after each swap if the flag is enabled */
            if (print_flag)
            {
                printf("[Swap %lu]: ", i + 1);
                for (k = 0; k < size; ++k)
                {
                    if (k > 0)
                        printf(", ");
                    printf("%d", array[k]);
                }
                printf("\n");
            }
        }
    }
}
