#include "add.h"

void merge_sort(int* array, int part_len, int len) {
	if (part_len >= len) {return;}
	int* first = (int*) malloc(sizeof(int) * (part_len + 1));
	int* second = (int*) malloc(sizeof(int) * (part_len + 1));
	for (int l = 0; l < len;) {
		for (int i = 0; i < part_len; i++) {
			first[i] = array[l + i];
            first[i + 1] = 0;
            if (len >= l + i + part_len) {
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
	merge_sort(array, part_len << 1, len);
}
