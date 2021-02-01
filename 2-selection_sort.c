#include "sort.h"

/**
 * selection_sort - sort an array with the selection method
 * @array: array to sort
 * @size: array size
 */

void selection_sort(int *array, size_t size)
{
	size_t i;
	size_t j;
	size_t save = 0;
	int tmp = 0;

	for (i = 0; i < size - 1; i++)
	{
		save = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[save])
				save = j;
		}
		if (array[save] != array[i])
		{
			tmp = array[i];
			array[i] = array[save];
			array[save] = tmp;
			print_array(array, size);
		}
	}
}
