#include "sort.h"
/**
 * quick_sort - sorts an array of integer in ascending
 * order.
 * @array: Array to sort.
 * @size: Size of the array @array.
 *
 * Return: nothing.
 */
void quick_sort(int *array, size_t size)
{
	if (array && size >= 2)
	{
		_quick_sort(array, size, 0, (int)(size - 1));
	}
}
/**
 * partition - Lomuto partition schame.
 * @array: array of integers.
 * @size: number of elements in @array.
 * @start: index of the firts element into @array.
 * @end: index of the last element into @array.
 *
 * Return: lomuto index.
 */
int partition(int *array, size_t size, int start, int end)
{
	int pivot, idx, j;

	pivot = array[end];
	idx = start;
	for (j = start; j < end; j++)
	{
		if (array[j] < pivot)
		{
			if (idx != j)
			{
				swap(array, j, idx);
				print_array(array, size);
			}
			idx++;
		}
	}
	if (idx != end)
	{
		swap(array, end, idx);
		print_array(array, size);
	}
	return (idx);
}
/**
 * _quick_sort - auxiliar quick sort.
 * @array: array of integers.
 * @size: number of elements in @array.
 * @start: index of the firts element into @array.
 * @end: index of the last element into @array.
 *
 * Return: nothing.
 */
void _quick_sort(int *array, size_t size, int start, int end)
{
	int pivote;

	if (start < end)
	{
		pivote = partition(array, size, start, end);
		_quick_sort(array, size, start, pivote - 1);
		_quick_sort(array, size, pivote + 1, end);
	}
}
/**
 * swap - swaps two elements from an array.
 * @array: array of integers.
 * @idx1: index of first element to swap.
 * @idx2: index of second elemtn to swap.
 *
 * Return: nothing.
 */
void swap(int *array, int idx1, int idx2)
{
	int t = array[idx1];

	array[idx1] = array[idx2];
	array[idx2] = t;
}

