#include "sort.h"

/**
 * bubble_sort - algorithm for bubble sorting an array
 * @array: array to sort
 * @size: size of array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i;
	int change_count;
	int tmp = 0;

	while (1)
	{
		change_count = 0;
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				change_count++;
				print_array(array, size);
			}
		}
		if (change_count == 0)
			break;
	}
}
