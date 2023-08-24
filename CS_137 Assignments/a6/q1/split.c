#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int **split(int a[], int n, int p, int *len1, int *len2){
    
    *len1 = 0;
    *len2 = 0;

    for(int i = 0; i < n; i++){
        if(a[i] <= p) (*len1)++;
        else (*len2)++;
    }

    int *L = malloc(*len1 * sizeof(int));
    assert(L);
    int *M = malloc(*len2 * sizeof(int));
    assert(M);
    int **array = malloc(2 * sizeof(*L));
    assert(array);

    int cntL = 0;
    int cntM = 0;

    for(int i = 0; i < n; i++){
        if(a[i] <= p){
            L[cntL] = a[i];
            cntL++;
        }
        else{
            M[cntM] = a[i];
            cntM++;
        }
    }

    array[0] = L;
    array[1] = M;

    return array;
}