#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

bool newSearch(int arr[], int len, int x){
    int b = 0;
    int a = len - 1;
    int pos;

    printf("start with the range %d to %d\n", arr[b], arr[a]);
    
    while(b <= a){

        if((x < arr[b]) || (x > arr[a])){
            printf("%d not in the range between %d and %d\n", x, arr[b], arr[a]);
            return false;
        }

        if(a-b == 0){
            pos = b;
        }
        else{
            // pos = (int) (b + ((a - b) * (x-arr[b]) / (arr[a]-arr[b])));
            pos = (b + ((double) (x - arr[b]) / (arr[a] - arr[b])) * (a - b));
        }

        if(arr[pos] == x){
            printf("%d was found in position %d\n", x, pos);
            return true;

        }
        else{
            if(x < arr[pos]){
            a = pos - 1;
            printf("move to search in the range between %d and %d\n", arr[b], arr[a]);
        }
        else{
            b = pos + 1;
            printf("move to search in the range between %d and %d\n", arr[b], arr[a]);
        }
        }
    
    }
    return false;
}

// int main(void)
//  {
//  int a[1] = {14};
//  assert(!newSearch(a,1,10));
//  printf("\n\n");
//  assert(newSearch(a,1,14));
//  printf("\n\n");
//  int b[13] = {1,4,5,7,12,23,44,67,89,100,120,121,122};
//  assert(!newSearch(b,13,0));
//  printf("\n\n");
//  assert(!newSearch(b,13,150));
//  printf("\n\n");
//  assert(newSearch(b,13,4));
//  printf("\n\n");
//  assert(newSearch(b,13,121));
//  printf("\n\n");
//  assert(newSearch(b,13,23));
//  printf("\n\n");
//  int c[20] = {-10,-4,5,7,12,23,44,67,89,100,120,121,122,200,210,222,300,301,303,500};
//  assert(!newSearch(c,20,55));
//  printf("\n\n");
//  assert(newSearch(c,20,12));
//  printf("\n\n");
//  return 0;
//  }
























//int a[23] = {9,15,19,23,30,37,40,43,57,58,76,80,88,91,95,100,104,114,119,123,125,140,141};
    //assert(newSearch(a, 23, 23));