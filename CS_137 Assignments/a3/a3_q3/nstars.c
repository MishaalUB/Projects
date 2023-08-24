#include <stdio.h>
#include <assert.h>

/*
//calculates number of digits of the number being input
int digits(long int n, int k){
    if (n > 0)
    {
        n = n/10;
        k++;
        return digits(n, k);
    }
    return k-1;
    
}

// power function
int power(int base, int a){
    if (a == 0) return 1;
    return (base * (power(base, a-1)));
}

int digitOne(long int n, int a){
    return (n / power(10, a-1));
}
int digitTwo(long int n, int a){
    return - (digitOne(n, a) * 10) + (n / power(10, a-2));
}

// n/10 will chop off last digit, n%10 will give last digit
void stars(long int n){
    if(n <= 10) printf("%d", n);
    else
    {
        int a = digits(n, 1);   // gives the number of digits
        int one = digitOne(n, a); //gives the first digit
        int two = digitTwo(n, a); //gives the second digit

    }

}

int main(void){
    printf("%d %d", digitOne(70104257, 6), digitTwo(7010257, 6));
}

*/

// write a helper function that calls itself - 

void helper(long int n, int last){
    if(n == 0) return;
    helper((long int) (n / 10), (long int) (n/100)%10);    //casting int so we dont have floats
    int k = n%10;
    if(k == last) printf("*%d", k);
    else if(k != last) printf("%d", k);
}

void stars(long int n){
    helper(n, (long int)(n/10)%10);
}