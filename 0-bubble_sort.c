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
 * bubble sort - Buble sort
 * @array: block of int array
 * @size: size of the array
 * 
 * 
*/

void bubble_sort(int *array, size_t size)
{
    size_t i;
    size_t j;

    if(array == NULL || size < 2)
    {
        return;
    }

    for ( i = 0; i < size -1; i++)
    {
            for(j = 0; j < size - i -1; j++)
            {
                if(array[j] > array[j+1])
                {
                    swap(&array[j], &array[j+1]);

                    print_array(array, size);
                }
            }
    }
}
