#include "sort.h"

/**
 * quick_sort - quicksort an array
 * @array: array to be sorted
 * @size: size of the array
 */

void quick_sort(int *array, size_t size)
{
	int lo = 0;
	int hi = size - 1;

	recursive(array, size, lo, hi);
}

/**
 * partition - organize the subarray
 * @array: array to sort
 * @size: size of array
 * @lo: lowest index
 * @hi: highest index
 * Return: index of pivot
 */

int partition(int *array, size_t size, int lo, int hi)
{
	int pivot = array[hi];
	int i = lo;
	int j;
	int save;

	for (j = lo; j < hi; j++)
	{
		if (array[j] < pivot)
		{
			save = array[i];
			array[i] = array[j];
			array[j] = save;
			if (array[j] != array[i])
				print_array(array, size);
			i++;
		}
	}
	save = array[i];
	array[i] = array[hi];
	array[hi] = save;
	if (array[i] != array[hi])
		print_array(array, size);
	return (i);
}

/**
 * recursive - recursive function to sort array
 * moves lo and hi indexes and partitions the array
 * @array: array to sort
 * @size: size of array
 * @lo: lowest index
 * @hi: highest index
 */

void recursive(int *array, size_t size, int lo, int hi)
{
	int i;

	if (lo < hi)
	{
		i = partition(array, size, lo, hi);
		recursive(array, size, lo, i - 1);
		recursive(array, size, i + 1, hi);
	}
}
