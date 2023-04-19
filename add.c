#include "add.h"

void print(int* array){
	int k = 0;
	while(array[k]){printf("%i ", array[k++]);} putchar('\n');
}

int len_cnt(int* array) {
    int i = 0;
    while(array[++i]);
    return i;
}

int first_no_under(int* array, int value, int start) {
    for (start; array[start] < value; start++);
    return start;
}