#include "add.h"

void redex_sort(int *array_copy)
{
	unsigned int abs_max = get_max(array_copy);
	unsigned int len = *array_copy;
	int *array = array_copy + 1;
	int **buffer = (int **)malloc(19 * sizeof(int *));
	buffer += 9;
	for (int i = -9; i < 10; i++)
	{
		buffer[i] = (int *)malloc((len + 1) * sizeof(int));
	}
	for (int redex = 10; redex / 10 <= abs_max; redex *= 10)
	{
		for (int i = -9; i < 10; i++)
		{
			buffer[i][0] = 0;
		}
		for (unsigned int i = 0; i < len; i++)
		{
			int key = (array[i] % redex) / (redex / 10); // printf("%i ", key);
			buffer[key][0] += 1;
			buffer[key][*(buffer[key])] = array[i];
		}
		unsigned int k = 0;
		for (int i = -9; i < 10; i++)
		{
			// print(buffer[i]);
			int red_len = buffer[i][0];
			for (unsigned int j = 1; j <= red_len; j++)
			{
				array[k++] = buffer[i][j];
			}
		}
	}
	for (int i = -9; i < 10; i++)
	{
		free(buffer[i]);
	}
	free(buffer -= 9);
}