#include "sort.h"

/**
 * swap_element - swaps two elements given
 * @a: element to swap
 * @b: element to swap
 */
void swap_element(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}
/**
 * partition_sort - divides the array into two(Lomuto
 * partition scheme) and recursively sort
 *
 * @array: array to partition and sort
 * @low: the starting index of the subarray to be sorted
 * @high: the ending index of the subarray to be sorted
 * @size: size of the array
 * Return: index of the pivot
 */
int partition_sort(int array[], int low, int high, size_t size)
{
	int i, j;
	int pivot;

	pivot = array[high];
	i = (low - 1);

	/* if the element is smaller than pivot we swap */
	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap_element(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	/* position the pivot in the right place */
	if (i + 1 != high)
	{
		swap_element(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	/* return index of the pivot */
	return (i + 1);
}
/**
 * recursive_sort - recursively sort a partition
 * @array: array to sort
 * @low: least index
 * @high: high index
 * @size: size of the array
 */
void recursive_sort(int array[], int low, int high, size_t size)
{
	int pi;

	if (low < high)
	{
		pi = partition_sort(array, low, high, size);
		recursive_sort(array, low, pi - 1, size);
		recursive_sort(array, pi + 1, high, size);
	}
}
/**
 * quick_sort - sort an array using quick sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	recursive_sort(array, 0, size - 1, size);
}
