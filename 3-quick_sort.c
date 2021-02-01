#include "sort.h"

/**
 * quick_sort - function that sorts an array with lomuto scheme
 * @array: array to sort
 * @size: size of array
 */

void quick_sort(int *array, size_t size)
{
	int lo = 0;
	int hi = size - 1;

	recursive(array, size, lo, hi);
}

/**
 * partition - arranges the array with a pivot in account
 * @array: array to check
 * @size: size of array
 * @lo: lowest index
 * @hi: highest index
 * Return: i as the pivot
 */

int partition(int *array, size_t size, int lo, int hi)
{
	int pivot = array[lo];
	int save = 0;
	int i = lo;
	int j = hi;

	while (i < j)
	{
		while (array[i] <= pivot)
			i++;
		while (array[j] > pivot)
			j--;
		if (i < j)
		{
			save = array[i];
			array[i] = array[j];
			array[j] = save;
			if (array[i] != array[j])
				print_array(array, size);
		}
	}
	save = array[lo];
	array[lo] = array[j];
	array[j] = save;
	if (array[j] != array[lo])
		print_array(array, size);
	return (j);
}
/**
 * recursive - recursive function that arranges the sublists
 * @array: array to arrange
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
		recursive(array, size, lo, i);
		recursive(array, size, i + 1, hi);
	}
}
