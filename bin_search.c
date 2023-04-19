#include "add.h"

int bin_search(int* massive, int value, int min_elem, int max_elem) {
    //if (massive[min_elem] > value || massive[max_elem] < value) {return -1;}
    if (min_elem == max_elem) {
        if (massive[min_elem] == value) {return min_elem;}
        else {return -1;}
    }
    int mid_elem = min_elem + (max_elem - min_elem) / 2;
    if (massive[mid_elem] == value) {return mid_elem;}
    else if (massive[mid_elem] > value) {return bin_search(massive, value, min_elem, mid_elem - 1);}
    else {return bin_search(massive, value, mid_elem + 1, max_elem);}
}