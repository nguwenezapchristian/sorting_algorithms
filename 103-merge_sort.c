#include "sort.h"

/**
 * merge_sort - this a topdown merge sort algorithm
 * @array: containes elements to sort
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *arrayCopyy;

	arrayCopyy = malloc(sizeof(int) * size);
	if (arrayCopyy == NULL)
	{
		perror("Error allocating memory");
	}
	/* one time copy of array */
	copyArray(array, 0, size, arrayCopyy);
	/* sort data from arrayCopyy */
	topDownSplitMerge(array, 0, size, arrayCopyy);
	free(arrayCopyy);
}
/**
 * topDownSplitMerge - split the array into small arrays and merge them
 * @arraycopyy: array copy
 * @iBegin: first index
 * @iEnd: last index
 * @array: array to split
 */
void topDownSplitMerge(int *arrayCopyy, int iBegin, int iEnd, int *array)
{
	int iMiddle;

	/* if array size == 1, return */
	if (iEnd - iBegin <= 1)
		return;
	/* split the array longer than 1 item into halves */
	iMiddle = (iEnd + iBegin) / 2;
	/* recursively sort both arrays into array[] into arrayCopyy[] */
	/* sort the left array */
	topDownSplitMerge(array, iBegin, iMiddle, arrayCopyy);
	/* sort the right array */
	topDownSplitMerge(array, iMiddle, iEnd, arrayCopyy);
	/*formatting display*/
	printf("Merging...\n");
	/* display the left array */
	printf("[left]: ");
	printArray(arrayCopyy, iBegin, iMiddle);
	/* display the right array */
	printf("[right]: ");
	printArray(arrayCopyy, iMiddle, iEnd);
	/* merge the resulting arrays from arrayCopyy[] into array[] */
	topDownMerge(arrayCopyy, iBegin, iMiddle, iEnd, array);
	printf("[Done]: ");
	printArray(arrayCopyy, iBegin, iEnd);
}
/**
 * topDownMerge - merge the small arrays
 * @arrayCopyy: small arrays
 * @iBegin: first index
 * @iMiddle: mid point
 * @iEnd: last index
 * @array: merged array
 */
void topDownMerge(int *arrayCopyy, int iBegin,
		int iMiddle, int iEnd, int *array)
{
	int i, b, n;

	i = iBegin;
	b = iMiddle;
	/* while there're elements in the left or right small array */
	for (n = iBegin; n < iEnd; n++)
	{
		/**
		 * if left small array head exits and is <= existing
		 * right small array
		 */
		if (i < iMiddle && (b >= iEnd || array[i] <= array[b]))
		{
			arrayCopyy[n] = array[i];
			i = i + 1;
		}
		else
		{
			arrayCopyy[n] = array[b];
			b = b + 1;
		}
	}
}
/**
 * copyArray - copy elements of an array
 * @array: array to be copied
 * @iBegin: first index of the array
 * @iEnd: last index of the array
 * @arrayCopyy: copy of the array
 */
void copyArray(int *array, int iBegin, int iEnd, int *arrayCopyy)
{
	int b;

	for (b = iBegin; b < iEnd; b++)
	{
		arrayCopyy[b] = array[b];
	}
}
/**
 * printArray - print small array
 * @array: array to print
 * @size: length of the array
 */
void printArray(int *array, int iBegin, int iMiddle)
{
	int i;

	i = iBegin;
	while (array && i < iMiddle)
	{
		printf("%d", array[i]);
		if (i < iMiddle - 1)
			printf(", ");
		++i;
	}
	printf("\n");
}
