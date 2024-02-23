#include "sort.h"

/**
 * swap_ints - swqps 2 ints
 * @a1: 1st int
 * @b1: 2nd int
 */

void swap_ints(int *a1, int *b1)
{
	int temp;

	temp = *a1;
	*a1 = *b1;
	*b1 = temp;
}

/**
 * selection_sort - sorts array of ints in ascending order
 * @array: array
 * @size: size of array
 */

void selection_sort(int *array, size_t size)
{
	int *m;
	size_t l, f;

	if (array == NULL || size < 2)
		return;
	for (l = 0; l < size - 1; l++)
	{
		m = array + l;
		for (f = l + 1; f < size; f++)
			m = (array[f] < *m) ? (array + f) : m;
		if ((array + l) != m)
		{
			swap_ints(array + l, m);
			print_array(array, size);
		}
	}
}
