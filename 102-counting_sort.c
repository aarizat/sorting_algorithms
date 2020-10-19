#include "sort.h"
/**
 * counting_sort - sorts an array in ascending order.
 * @array: array of integer to sort.
 * @size: size of @array.
 *
 * Return: nothing.
 */
void counting_sort(int *array, size_t size)
{
	int max, *count, *aux_arr, i;

	if (!array || size < 2)
		return;
	max = array[0];
	for (i = 1; i < (int)size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	count = malloc(sizeof(int) * (max + 1));
	if (!count)
		return;
	for (i = 0; i <= max; i++)
		count[i] = 0;
	for (i = 0; i < (int)size; i++)
		count[array[i]]++;
	for (i = 1; i <= max; i++)
		count[i] += count[i - 1];
	for (i = 0; i < max + 1; i++)
	{
		if (i > 0)
			printf(", ");
		printf("%d", count[i]);
	}
	printf("\n");
	aux_arr = malloc(sizeof(int) * size);
	if (!aux_arr)
		return;
	for (i = 0; i < (int)size; i++)
		aux_arr[--count[array[i]]] = array[i];
	for (i = 0; i < (int)size; i++)
		array[i] = aux_arr[i];
	free(count);
	free(aux_arr);
}
