#include "sort.h"

/**
 * bubble_sort - this function sorts an array of integers in
 * ascending order using the bubble sort algorithm
 *
 * @array: array to sort
 * @size: length of the array
 */
void bubble_sort(int *array, size_t size)
{
	int temp;
	int *first, *second;
	size_t i, j;
	bool swapped;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		swapped = false;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				first = &array[j];
				second = &array[j + 1];
				temp = *first;
				*first = *second;
				*second = temp;
				swapped = true;
				print_array(array, size);
			}
		}
		if (swapped == false)
			break;
	}
}
