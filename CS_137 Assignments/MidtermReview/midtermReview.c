#include<stdio.h>
#include<assert.h>
// #include<stdbool.h>

/*bool canComplete(int i, int arr[], int len){
    int sum = arr[i];
    int move = i + arr[i];
    while(sum < len){
        if (arr[i] == 0) return false;
        if (arr[i+1] != 0){ // if the next index is non-zero, we can just move 1
            sum++;
            i++;
        }
        else if (arr[i] == 1 && arr[i+1] == 0) return false; // i
        else if (arr[i] > 1){
            for(move = i + arr[i]; move >= i+1; move--){
                if (move < len) break; // not sure about this line
            }
            for(move; move > i+1; move--){
                if (arr[move] != 0) break;
            }
            i = move;
            sum += move;
        }
    }
    if (sum == len)
    {
        return true;
    }
    else return false;
}*/

/* void butterfly (int rows){

    for(int i = 1; i <= rows; i++){

        for(int j = 1; j <=i; j++){
            printf("%d", j);
        }
        for(int k = 1; k <= 2*(rows-i)-1; k++){
            printf(" ");
        }
        if (i == rows){
            for(int m = rows-1; m > 0; m--){
                printf("%d", m);
            }
            printf("\n");
        }
        else{
        for(int m = i; m > 0; m--){
            printf("%d", m);
        }
        printf("\n");
        }   
    }

    for(int i = rows-1; i > 0; i--){
            for(int j = 1; j <= i; j++){
                printf("%d", j);
            }
            for (int k = 1; k <= 2*(rows-i)-1; k++){
                printf(" ");
            }
            for(int m = i; m > 0; m--){
                printf("%d", m);
            }

    printf("\n");
    }
}*/

/*void pyramid (int n){
    int rows = n - (n/2);
    for(int i = 1; i <= rows; i++){
        int k = (2*i) - 1;
        for(int j = i; j <= k; j++){
            printf("%d", j);
        }
        printf("\n");
    }
    for(int i = n/2; i > 0; i--){
        int k = (2*i) - 1;
        for(int j = i; j <= k; j++){
            printf("%d", j);
        }
        printf("\n");
    }
}*/

/*int helperPath(int m, int n, int a[m][n], int x, int y){
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
}*/

// m = 3 , n = 3
// x = 2 , y = 2


/*int monotonePath(int m, int n, int a[m][n]){
    return helperPath(m, n, a, m-1, n-1);
}*/


int main(void){
    /*int n;
    scanf("%d", &n);
    for(int i = 0; i < 10; i++){  // 
        int cnt = 0;
        int user = n;
        while(user > 0){
            if (i == user%10){
                cnt ++;
            }
            user = user/10;
        }
        printf("%d %d\n", i, cnt);
    }*/
    int i = 2;
    i = 1/i;
    printf("%d\n", i);






}