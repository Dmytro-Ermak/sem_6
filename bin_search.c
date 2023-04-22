#include "add.h"

int bin_search(int* massive_copy, int value, int min_elem, int max_elem) {
    int* massive = massive_copy + 1;
    //printf("%i %i %i %i\n", massive[min_elem], min_elem, massive[max_elem], max_elem);
    if (massive[min_elem] > value || massive[max_elem] < value) {return -1;}
    if (massive[min_elem] == value) {return min_elem;} //максимальный элемент вызовет баги
    int mid_elem = min_elem + (max_elem - min_elem) / 2;
    if (massive[mid_elem] == value && massive[mid_elem - 1] != value) {return mid_elem - 1;}
    else if (massive[mid_elem] > value || (massive[mid_elem] == value && massive[mid_elem] == massive[mid_elem - 1])) {return bin_search(massive_copy, value, min_elem, mid_elem - 1);}
    else {return bin_search(massive_copy, value, mid_elem + 1, max_elem);}
}