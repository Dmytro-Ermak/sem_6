#include "sort.h"
#include "bin.h"
#include "add.h"

int main() {
    int a[] = {3,4,1,3,43,23,4325,2,6,566,33,323,6753,8,99,33,322,4,5,53,6,7,22,23643,563,32344,5553,64};
    int len = sizeof(a) / sizeof(a[0]);
    int* copy_a = (int*) malloc(sizeof(int) * (len + 2));
    int* copy_b = (int*) malloc(sizeof(int) * (len + 2));
    *copy_a = len;
    *copy_b = len;
    int m = 1;
    for (; m <= len; m++) {
        copy_a[m] = a[m - 1];
        copy_b[m] = a[m - 1];
    }
    copy_a[m] = 0;
    copy_b[m] = 0;    
    //print(copy_a);
    //printf("%i\n%i\n", copy_a[28], copy_b[28]);
    print(copy_a);
    quick_sort(copy_a);
    merge_sort(copy_b, 1, *copy_b);
    int i = bin_search(copy_a, 3, 0, *copy_a - 1);
    int k = bin_search(copy_b, 323, 0, *copy_b - 1);
    int j = 0;
    print(copy_a);
    printf("%i\n%i\n", i, k);
    j = 0;
    print(copy_b);
    return 0;
}