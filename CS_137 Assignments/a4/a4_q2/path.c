#include<stdio.h>
#include<assert.h>


int helperPath(int m, int n, int a[m][n], int x, int y){
    if(x == 0 && y == 0) return a[x][y];
    if(y == 0){
        if(a[x][y] == 1){
            return helperPath(m, n, a, x-1, y); // just use a not a[m][n]
        }
    }
    if(x == 0){
        if(a[x][y] == 1){
            return helperPath(m, n, a, x, y-1);
        }
    }
    if (a[x][y] == 1){
        return helperPath(m, n, a, x, y-1) || helperPath(m, n, a, x-1, y);
    }
}

// m = 3 , n = 3
// x = 2 , y = 2


int monotonePath(int m, int n, int a[m][n]){
    return helperPath(m, n, a, m-1, n-1);
}