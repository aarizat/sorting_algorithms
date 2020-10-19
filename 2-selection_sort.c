#include "sort.h"
/**
 * selection_sort - Sorts an array in ascending order using
 * selection sort algorithm.
 * @array: Array to sort.
 * @size: number of elements that contain @array.
 *
 * Return: nothing.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, idx_min;
	int tmp;

	if (array && size >= 2)
	{
		for (i = 0; i < size; i++)
		{
			idx_min = i;
			for (j = i + 1; j < size; j++)
			{
				if (array[j] < array[idx_min])
				{
					idx_min = j;
				}
			}
			if (idx_min != i)
			{
				tmp = array[i];
				array[i] = array[idx_min];
				array[idx_min] = tmp;
				print_array(array, size);
			}
		}
	}
}
