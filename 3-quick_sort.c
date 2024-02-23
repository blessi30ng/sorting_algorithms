#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

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
 * lomuto_partition - Order a subset of an array of integers according to
 *              the lomuto partition scheme
 * @array: array
 * @size: size of array
 * * @l: starting index of array partition to order
 * @r: ending index of array partition to order
 * Return: final partition i
 */

int lomuto_partition(int *array, size_t size, int l, int r)
{
	int *driver, u, d;

	driver = array + r;
	for (u = d = l; d < r; d++)
	{
		if (array[d] < *driver)
		{
			if (u < d)
			{
				swap_ints(array + d, array + u);
				print_array(array, size);
			}
			u++;
		}
	}
	if (array[u] > *driver)
	{
		swap_ints(array + u, driver);
		print_array(array, size);
	}
	return (u);
}

/**
 * lomuto_sort - quickest sort algo through recursion
 * @array: array
 * @size: size of array
 * @l: starting index of array partition to order
 * @r: ending index of array partition to order
 */

void lomuto_sort(int *array, size_t size, int l, int r)
{
	int bel;

	if (r - l > 0)
	{
		bel = lomuto_partition(array, size, l, r);
		lomuto_sort(array, size, l, bel - 1);
		lomuto_sort(array, size, bel + 1, r);
	}
}

/**
 * quick_sort - sort an array of ints in ascending order
 * @array: array of ints
 * @size: size of array
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
