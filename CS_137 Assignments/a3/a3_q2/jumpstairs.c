#include <stdio.h>
#include <assert.h>

int jump_stair_v1(int n){
    if(n<=1) return 1;
    return jump_stair_v1(n - 1) + jump_stair_v1(n - 2);
}
// Jumps 2 or Walks 1 but it has to be 3 times in a row? (121, 222, 232, 565, 8108, ...)
//  (fib inside a fib or more like 2 fibs)
int helpv2(int n, int count, int k){
    n = n - k;
    count++;
    if(n < 0) return 0;
    if(n == 0) return 1;
    if(count < 3) return helpv2(n, count, k);
    return helpv2(n, 0, 1) + helpv2(n, 0, 2);
}

int jump_stair_v2(int n){
    /*if(n == 1) return 1;
    if(n == 2) return 2;
    if(n == 3) return 1;*/
    return helpv2(n, 0, 1) + helpv2(n, 0, 2);
}

int helpv3(int n, int count, int k){
    n = n - k;
    count ++;
    if(n < 0) return 0;
    if(n == 0 && count == 3) return 1;
    if (count < 3) return helpv3(n, count, k);
    return helpv3(n, 0, 2) + helpv3(n, 0, 3);
}

int jump_stair_v3(int n){
    return helpv3(n, 0, 2) + helpv3(n, 0, 3);
}