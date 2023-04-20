#include "add.h"

void merge_sort(int* array_copy, int part_len) {
	putchar('\n');print(array_copy);putchar('\n');
	int* array = array_copy + 1;
	if (part_len >= *array_copy) {return;}
	int* first = (int*) malloc(sizeof(int) * (part_len + 1));
	int* second = (int*) malloc(sizeof(int) * (part_len + 1));
	for (int l = 0; l < *array_copy;) {
		for (int i = 0; i < part_len; i++) {
			first[i] = array[l + i];
            first[i + 1] = 0;
            if (*array_copy >= l + i + part_len) {
            	second[i] = array[l + i + part_len];
            } else {
            	second[i] = 0;
            }
            second[i + 1] = 0;
			//puts("first:");print(first);puts("second");print(second);
		}
		int j = 0;
		for(int i = 0; i + j < 2 * part_len;) {	
			if (first[i] == 0 && second[j] == 0) {
				break;
			} else if (second[j] == 0) {
				array[l++] = first[i++];
			} else if (first[i] == 0) {
				array[l++] = second[j++];
			} else if (first[i] > second[j]) {
				array[l++] = second[j++];
			} else if (first[i] <= second[j]) {
				array[l++] = first[i++];
			}
		}
		
	}
	free(first);
	free(second);
	merge_sort(array_copy, part_len << 1);
}
