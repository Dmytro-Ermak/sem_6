#include "add.h"

void merge_sort(int* array_copy, int part_len) {
	//putchar('\n');print(array_copy);putchar('\n');
	int len = *array_copy;
	int* array = array_copy + 1;
	if (part_len >= len) {return;}
	int* first = (int*) malloc(sizeof(int) * (part_len + 1));
	int* second = (int*) malloc(sizeof(int) * (part_len + 1));
	for (int l = 0; l < len;) {
		int j_max = 0;
		for (int i = 0; i < part_len; i++) {
			first[i] = array[l + i];
            if (len > l + i + part_len) {
            	second[i] = array[l + i + part_len];
				j_max++;
            }
			//puts("first:");printf("%i\n",first[i]);puts("second:");printf("%i\n",second[i]);
		}
		int j = 0;
		int k = 0;
		for(int i = 0; i + j < part_len + j_max;) {			
			if ((first[i] >= second[j] || i == part_len) && j < j_max) {
				array[l++] = second[j++];
			} else if ((first[i] <= second[j] || j == j_max) && i < part_len) {
				array[l++] = first[i++];
			}
		}	
	}
	//print(array_copy);
	free(first);
	free(second);
	merge_sort(array_copy, part_len << 1);
}
