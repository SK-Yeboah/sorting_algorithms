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
 * shell_sort - Sorts an array of integers in ascending order using
 *              the Shell sort algorithm with the Knuth sequence
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */

void shell_sort(int *array, size_t size)
{

    int gap;
    size_t j;
    int i;
    size_t k;

    if(array == NULL || size <= 1)
    {
        return;
    }

   
    
    /*Generate the Gap*/ 
    for(gap = size/2; gap >=1; gap /= 2)
    {
        for(j = gap; j < size; j++)
        {
            for( i =j-gap; i >=0; i-= gap)
            {
                if(array[i + gap] > array[i])
                {
                    break;
                }else
                {
                    swap(&array[i+gap], &array[i]);

                    /* Print the array after each swap */
                    /*printf("[Swap]: ");*/ 
                    for ( k = 0; k < size; ++k)
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
}