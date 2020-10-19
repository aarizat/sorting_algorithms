#include "sort.h"
/**
 * shell_sort - sorts an array in ascending order.
 * @array: array to sort.
 * @size: number of items in @array.
 *
 * Return: nothing.
 */
void shell_sort(int *array, size_t size)
{
	int i, j, tmp;
	int h = 1;

	while (h < (int)size / 3)
	{
		h = 3 * h + 1;
	}
	while (h > 0)
	{
		for (i = h; i < (int)size; i += h)
		{
			for (j = i; j > 0 && array[j] < array[j - h]; j -= h)
			{

				tmp = array[j];
				array[j] = array[j - h];
				array[j - h] = tmp;
			}
		}
		print_array(array, size);
		h = (h - 1) / 3;
	}


}
