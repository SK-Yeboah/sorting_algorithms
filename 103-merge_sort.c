
#include "sort.h"

/**
 * merge - Merges two subarrays into a sorted array
 * @array: The original array
 * @size: Total size of the array
 * @left: Pointer to the left subarray
 * @left_size: Size of the left subarray
 * @right: Pointer to the right subarray
 * @right_size: Size of the right subarray
 */
void merge(int *array, size_t size, int *left, size_t left_size, int *right, size_t right_size)
{
    size_t i, j, k;
    int *merged;

    printf("Merging...\n");

    merged = malloc(size * sizeof(int));
    if (merged == NULL)
        return;

    i = j = k = 0;

    while (i < left_size && j < right_size)
    {
        if (left[i] <= right[j])
            merged[k++] = left[i++];
        else
            merged[k++] = right[j++];
    }

    while (i < left_size)
        merged[k++] = left[i++];

    while (j < right_size)
        merged[k++] = right[j++];

    for (k = 0; k < size; ++k)
        array[k] = merged[k];

    free(merged);

    printf("[Done]: ");
    print_array(array, size);
    /*printf("\n");*/
}
/**
 * merge_sort - Sorts an array of integers in ascending order
 *               using the Merge sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void merge_sort(int *array, size_t size)
{
    if (array == NULL || size <= 1)
        return;

    if (size > 1)
    {
        size_t mid = size / 2;
        int *left = array;
        size_t left_size = mid;
        int *right = array + mid;
        size_t right_size = size - mid;

        printf("Splitting...\n");
        printf("[left]: ");
        print_subarray(array, 0, mid - 1);
        printf("\n[right]: ");
        print_subarray(array, mid, size - 1);
        printf("\n");

        merge_sort(left, left_size);
        merge_sort(right, right_size);

        merge(array, size, left, left_size, right, right_size);
    }
}


/**
 * print_subarray - Prints a subarray in square brackets with commas
 *                  between elements.
 *
 * @array: The array containing the subarray.
 * @start: Index of the first element in the subarray.
 * @end: Index of the last element in the subarray.
 *
 */
void print_subarray(const int *array, size_t start, size_t end)
{
    size_t i;
    printf("[");
    for (i = start; i <= end; ++i)
    {
        if (i > start)
            printf(", ");
        printf("%d", array[i]);
    }
    printf("]");
}