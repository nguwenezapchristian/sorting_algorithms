#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "sort.h"
/**
 * selection_sort - This is a selction sort algorithm
 * @array: The array
 * @size: size of the array
 *
 * Return: void
 */

void selection_sort(int *array, size_t size)
{
	/**
	 * The way this function works is that it puts the
	 * least value at the front of the list anb the
	 * concurring least values behind it
	 *
	 * Check the task for reference
	 */
	int least_value;
	int least_index;
	size_t loop  = 0;
	size_t i;
	int temp;
	/**
	 * what i am going to do is to loop size times
	 */
	for (loop = 0; loop < size; loop++)
	{
		/*set the least value to the first value on the list*/
		least_value = array[loop];
		for (i = loop; i < size; i++)
		{
			if (array[i] < least_value)
			{
				least_value = array[i];
				least_index = i;
			}
		}
		i = loop;
		if (array[i] != least_value)
		{
			/*swap*/
			temp = array[i];
			array[i] = least_value;
			array[least_index] = temp;
			print_array(array, size);
		}
	}
}
