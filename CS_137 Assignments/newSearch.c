#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

bool newSearch(int arr[], int len, int x){
    int b = 0;
    int a = len - 1;
    int pos;

    printf("start with the range %d to %d\n", arr[b], arr[a]);
    
    while(b <= a){

        if(x < arr[b] || x > arr[a]){
            printf("%d not in the range between %d and %d\n", x, arr[b], arr[a]);
            return false;
        }

        if(a-b == 0){
            pos = b;
        }
        else if(arr[a]-arr[b] == 0){
            pos = a;
        }
        else{
            pos = (int) (b + ((a - b) * (x-arr[b])/ (arr[a]-arr[b])));
        }
        // printf("%d\n", pos);

        if(arr[pos] == x){
            printf("%d was found in position %d\n", x, pos);
            return true;

        }
    
        if(x < arr[pos]){
            a = pos - 1;
            printf("move to search in the range between %d and %d\n", arr[b], arr[a]);
        }
        else if(x > arr[pos]){
            b = pos + 1;
            printf("move to search in the range between %d and %d\n", arr[b], arr[a]);
        }
    
    }
    return false;
}