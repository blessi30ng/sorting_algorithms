#include "sort.h"

/**
 * swap_int - swaps 2 integers in an array
 * @a: 1st int
 * @b: 2nd int
 */

void swap_int(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * bubble_sort - sort array of ints in ascending order
 * @array: An array of integers to sort
 * @size: size of array
 */

void bubble_sort(int *array, size_t size)
{
	size_t k, length = size;
	bool bubble = false;

	if (array == NULL || size < 2)
		return;

	while (bubble == false)
	{
		bubble = true;
		for (k = 0; k < length - 1; k++)
		{
			if (array[k] > array[k + 1])
			{
				swap_int(array + k, array + k + 1);
				print_array(array, size);
				bubble = false;
			}
		}
		length--;
	}
}
