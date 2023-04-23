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

unsigned int get_max (int* array) {
	unsigned int max = 0;
	for (int i = 1; i <= *array; i++) {
		if (array[i] < 0) {
			if (array[i] * (-1) > max) {
				max = array[i] * (-1);
			}
		} else {
			if (array[i] > max) {
				max = array[i];
			}
		}
	}
	return max;
}

char* get_str() {
    char symb;
    char* string = (char*) calloc(0, sizeof(char));           
        for (unsigned int j = 0; (symb = getchar()) != '\n'; ++j) {
            if (!(j % 10)) {
                string = (char*) realloc(string, (j + 11) * sizeof(char));
            }
            string[j] = symb;
            string[j + 1] = '\0';
        }
    return string;
}

int get_num() {
	int num;
	char* str;
	do {
		str = get_str();
		num = atoi(str);
		if (num == 0) {
			if (*str == '0') {
				free(str);
				break;
			}
			else {
				puts("error num, input again");
			}
		}
		free(str);
	} while (!num);
	return num;
}
int* get_array() {
	printf("Input count of elements in array: ");
	int len = get_num();
	int* array = (int*) malloc(sizeof(int) * (len + 1));
	*array = len;
	printf("Input num %i times=\n", len);
	for (int i = 1; i <= len; i++) {
		array[i] = get_num();
	}
	puts("u input full array");
	return array;
}
