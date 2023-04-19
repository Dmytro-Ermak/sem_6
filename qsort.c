#include "swap.h"
#include "add.h"

void quick_sort(int array[]) {
    int len = len_cnt(array);
    int arrays_len = 0;
    int *arrays = (int *) malloc(sizeof(int) * (5 + arrays_len));
    arrays[arrays_len++] = 1;
    arrays[arrays_len++] = len;
    arrays[arrays_len++] = 1;
    arrays[arrays_len++] = 1;
    arrays[arrays_len] = 0;
    if (arrays[0] >= arrays[1]) {
        return;
    }
    int i = 0;
    while (arrays[i]) {
        int start = (arrays[i++]) - 1;
        int anchor_location = (arrays[i++]) - 1;
        int old_anchor = anchor_location;
        int anchor_prev = anchor_location - 1;
        if (anchor_location - start <= 1) {
            if (array[anchor_location] < array[start] && start < anchor_location) {
                SWAP(array[anchor_location], array[start]);
            }     
        continue;
        }
        int anchor = array[anchor_location];
        for (int j; (j = first_no_under(array, anchor, start)) != anchor_location;
            anchor_location--, anchor_prev--) {
            SWAP(array[j], array[anchor_prev]);
            SWAP(array[anchor_prev], array[anchor_location]);
        }
        //print(array);
        arrays = (int*) realloc(arrays, (arrays_len + 5) * sizeof(int));
        //printf("%i %i %i\n", start, anchor_location, arrays[i - 1]);
        arrays[arrays_len++] = start + 1;
        arrays[arrays_len++] = anchor_location;
        arrays[arrays_len++] = anchor_location + 2;
        arrays[arrays_len++] = arrays[i - 1];
        arrays[arrays_len] = 0;
        //k = 0;
        //while (arrays[k]) {
        //printf("%i ", arrays[k++]);
        //}
        //arrays[arrays_len + 4] = 0;
    }
    free(arrays);
    return;
}