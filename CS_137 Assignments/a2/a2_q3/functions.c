/* implement all functions from functions.h into functions.c*/
#include <stdio.h>
#include <assert.h>
#include "functions.h"

int isSophieGermainPrime(int n){

    if (n <= 1)
    {
        return 0;
    }
    for (int i = 2; i*i <= n; i++)
{
    if (n%i == 0)
    {
        return 0;
    }
}
    for (int i = 2; i*i <= (2*n+1); i++)
    {
        if ((2 * n+1) % i == 0)
        {
            return 0;
        }
    }
    
    return 1;
}
/* A Sophie Germain1 prime is a [positive] prime number p such that 2p + 1 is also a prime
number. For example, 2 is a Sophie Germain prime since both 2 and 2(2) + 1 = 5 are prime numbers. */


int power(int base, int n) {
    if(n == 0){
        return 1;
    }
    int sum = base;
    for (int i = 0; i < n - 1; i++){
        sum*=base;
    }
    return sum;
}

/* Thoughts: n%10 will give the last integer, n/10 will truncate the last digit off*/
int base2nat(int bs, int num){
    int a = 0;
    int sum=0;
    while(num>0)
    {
        int lastDigit = num%10;
        int decimal = power(bs,a) * lastDigit;
        sum += decimal;
        a++;
        num = (int)(num/10);
    }
    return sum;
}


int nat2base(int bs, int num){
    /*int b = num;
    while (b > 0)0
    {
        int a = b%bs;
        printf("%d", (b%bs));
        b = b/bs;
    }*/
    int a = 0;
    int b = 0;
    while (num > power (bs, a))
    {
        a++;
    }
    for (int i = a; i >= 0; i--)
    {
        int p = power(bs,i);
        int digit = (int)(num / p);
        num -= digit * p;
        b = 10 * b + digit;
    }

    return b;
}


/*int main(void){
    assert(isSophieGermainPrime(11));
    assert(isSophieGermainPrime(41));
    assert(base2nat(5,23114)==1659);
    assert(base2nat(7,1)==1);
    assert(base2nat(3,1211012)==1328);
    assert(nat2base(5,1659)==23114);
    assert(nat2base(9,1331)==1738);
}*/