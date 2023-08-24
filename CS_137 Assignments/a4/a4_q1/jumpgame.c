#include<stdio.h>
#include<stdbool.h>
#include<assert.h>


bool canComplete(int i, int arr[], int len){
    if (len == 1) return true;
    if (i == len) return true;
    if (i > len) return false;
    for (int k = arr[i]; k > 0; k--)
    {
        if (canComplete(i+k, arr, len)) return true;
    }
    return false;
}