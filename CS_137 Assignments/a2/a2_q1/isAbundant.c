/*#include<stdio.h>

    // Let O(n) be the sum of all positive proper divisors of an integer n, that is the sum of
    // the positive divisors not equal to the number


    int isAbundant(int n){
        int sum = 0;
        for (int i = 1; i < n-1; i++)
        {
            if (n%i == 0)
            {
                int sum = sum + (n/i);
            }
            
        }
        return sum;
    }

    int main(void){

        int n;
        scanf("%d", &n);
        int abundant = isAbundant(n);

    if (abundant == n)
    {
        printf("Perfect\n");
    }
    else if (abundant > n)
    {
        printf("Abundant\n");
    }
    else if (abundant < n)
    {
        printf("Deficient\n");
    }
    printf("%d", abundant);
    return 0;
}*/

#include<stdio.h>

    /* Let O(n) be the sum of all positive proper divisors of an integer n, that is the sum of
     the positive divisors not equal to the number */


    int isAbundant(int n){
        int sum = 0;
        for (int i = 1; i < n; i++) // you dont want to loop to < n-1 because < already implies it wont loop to n-1 so you'd loop to n-2 which would be missing the last possible divisor
        {
            if (n%i == 0)
            {
                sum += i; // you dont want to declare a new integer but instead add the positive divisor to the sum
            }

        }
        return sum;
    }

int main(void){
    int n;
    scanf("%d", &n);
    int abundant = isAbundant(n);

    if (abundant == n)
    {
        printf("Perfect\n");
    }
    else if (abundant > n)
    {
        printf("Abundant\n");
    }
    else if (abundant < n)
    {
        printf("Deficient\n");
    }
    return 0;
}