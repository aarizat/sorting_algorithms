#include "sort.h"
/**
 * bubble_sort - sorts an array of integers by using bubble sort
 * algorithms.
 * @array: Array of integer to sort.
 * @size: Number of elements in @array.
 *
 * Return: nothing.
 */
void bubble_sort(int *array, size_t size)
{
	int tmp, swapped = 0;
	size_t i, j;
	size_t k = size - 1;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < k; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				swapped = 1;
				print_array(array, size);
			}
		}
		k--;
		if (!swapped)
		{
			break;
		}
	}
}
