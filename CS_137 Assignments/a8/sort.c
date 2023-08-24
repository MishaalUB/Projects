#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

// void *arr; they will pass the structure of point
// int n; they will pass the number of struct points in the __
// elemsize; size of(struct point)
// bool *compare; will put pointcompare1, pointcompare2, pointcompare3 etc.
// void (*swap); will put pointSwap

void sort(void *arr, int n, size_t elemsize, bool (*compare)(const void *a, const void *b), void (*swap)(void *a, void *b)){

    int i, j;

    for(int i = 1; i < n; i++){
        for(int j = i; j > 0 && compare(((char *) arr) + j * elemsize, ((char *) arr) + (j-1) * elemsize); j--){
            swap(((char *) arr) + j * elemsize, ((char *) arr) + (j-1) * elemsize);
        }
    }
}