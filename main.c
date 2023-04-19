#include "sort.h"
#include "bin.h"
#include "add.h"

int main() {
    int a[] = {3,4,1,3,43,23,4325,2,6,566,33,323,6753,8,99,33,322,4,5,53,6,7,22,23643,563,32344,5553,64,0};
    int b[] = {3,4,1,3,43,23,4325,2,6,566,33,323,6753,8,99,33,322,4,5,53,6,7,22,23643,563,32344,5553,64,0};
    int len_a = len_cnt(a);
    int len_b = len_cnt(b);
    quick_sort(a);
    merge_sort(b, 1, len_cnt(b));
    int i = bin_search(a, 3, 0, len_a);
    int k = bin_search(a, 323, 0, len_b);
    int j = 0;
    print(a);
    printf("%i\n%i\n", i, k);
    j = 0;
    print(b);
    return 0;
}