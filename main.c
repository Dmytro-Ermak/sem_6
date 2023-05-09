#include "sort.h"
#include "bin.h"
#include "add.h"

int main()
{
    puts("input array 1: ");
    int *a = get_array();
    puts("input array 2: ");
    int *b = get_array();
    puts("input array 3: ");
    int *c = get_array();
    quick_sort(a);
    merge_sort(b, 1, *b);
    redex_sort(c);
    puts("result of quick sort 1st set");
    print(a);
    puts("result of merge sort 2nd set");
    print(b);
    puts("result of redex sort 3rd set");
    print(c);
    puts("find num in 1 array");
    int num = get_num();
    int id = bin_search(a, num, 0, *a - 1);
    puts("check:");
    if (id >= 0)
    {
        printf("id: %i, elem with this id: %i\n", id, (a + 1)[id]);
    }
    else
    {
        puts("this elem not in set");
    }

    puts("find num in 2 array");
    num = get_num();
    id = bin_search(b, num, 0, *b - 1);
    puts("check:");
    if (id >= 0)
    {
        printf("id: %i, elem with this id: %i\n", id, (b + 1)[id]);
    }
    else
    {
        puts("this elem not in set");
    }

    puts("find num in 3 array");
    num = get_num();
    id = bin_search(c, num, 0, *c - 1);
    puts("check:");
    if (id >= 0)
    {
        printf("id: %i, elem with this id: %i\n", id, (c + 1)[id]);
    }
    else
    {
        puts("this elem not in set");
    }
    return 0;
}