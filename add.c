#include "add.h"

void print(int* array) {
	for(int k = 1; k < *array + 1; k++) { 
        printf("%i ", array[k]);
    } 
    putchar('\n');
}

int len_cnt(int* array) {
    int i = 0;
    for(; array[i+1]; i++) {
        //printf("%i %i\n", array[i], i);
    }
    return i;
}

int first_no_under(int* array, int value, int start) {
    for (start; array[start] < value; start++);
    return start;
}