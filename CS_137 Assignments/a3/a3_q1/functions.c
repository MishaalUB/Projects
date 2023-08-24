#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

/*int mult(int a, int k){

}

bool help(int a, int b, int k){
    int sum = a*k;
    if(a < 0 || b < 0) return false;
    if(sum == b) return true;
    else if(k == b) return false;
    help(a, b, (k+1));
}

bool divide(int a, int b){
    return help(a, b, 1);
}

int main(void){
    int a;
    int b;
    scanf("%d %d", &a, &b);
    printf("%d", divide(a, b));
}*/

bool help(int a, int b, int k){
    if(a == b || a == -b || -a == b) return true;
    else if (a > b && a > 0 && b > 0) return false;
    if(a < 0 && b < 0 && a < b) return false;
    return help(a+k, b, k);
}


bool divide(int a, int b){
    if (a == 0 || b == 0) return false;
    return help(a, b, a);
}


/* PART B; IntegerDivision(int a, int b); the function returns the integer division of a by b
Assume: Both a and b are positive. No % */

int CounterDivision(int a, int b, int k, int count){
    if(a-b < k) return count;
    else if(a<b) return 0;
    if(a == b) return count;
    CounterDivision(a, b+k, k, count+1);
}

int IntegerDivision(int a, int b){
    return CounterDivision(a, b, b, 1);

}
