#include "sort.h"

/**
 * counting_sort - Sorts an array of integers using the Counting Sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */


void counting_sort(int *array, size_t size)
{
    size_t i;
    int i;
    int *count;

    if (array == NULL || size <= 1)
    {
        return;
    }

    /*find the maximum number*/
    int max = array[0];
    for(i = 1; i < size; size ++)
    {
        if(array[i]>max)
        {
            max == array[i];
        }
    }

    
    count = malloc((max + 1)*sizeof(int));
    if(count == NULL)
    {
        return;
    }

    for(i = 0; i<=max; i++)
    {
        count[i] = 0;
    }

    for(i = 0; i < size; i++)
    {
        count[array[i]]++;
    }

    


}