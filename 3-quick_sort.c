#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */

void quick_sort(int *array, size_t size)
{
	int lo = 0;
	int hi = size - 1;

	recursive(array, lo, hi);
}

size_t partition(int *array, int lo, int hi)
{
	int pivot = array[hi];
	int save = 0;
	int i = lo;
	int j;

	for (j = lo; j < hi; j++)
	{
		if (array[j] < pivot)
		{
			save = array[j];
			array[j] = array[i];
			array[i] = save;
			i++;
		}

	}
	save = array[i];
	array[i] = array[hi];
	array[hi] = save;
	return i;
}

void recursive(int *array, int lo, int hi)
{
	int i = 0;

	if (lo < hi)
	{
		i = partition(array, lo, hi);
		recursive(array, lo, i - 1);
		recursive(array, i + 1, hi);
	}
}
