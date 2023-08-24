#include<stdio.h>

int main(void){

    int num;
    int denom;
    scanf("%d %d", &num, &denom);
    int i = num/denom;
    int a = num%denom;
    
    if (a == 0)
    {
        printf("%d\n",i);
    }
    else
    {
        if ((num < 0 && denom > 0) || (denom < 0 && num >0))
        {
            i = i - 1;
            printf("%d\n", i);
        }
        else
        {
            i = i + 1;
            printf("%d\n", i);
        }
        
    }
    
    return 0;
}