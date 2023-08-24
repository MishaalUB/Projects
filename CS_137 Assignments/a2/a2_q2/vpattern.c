#include <stdio.h>

int main(void){
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("%d",j);
        }

        for (int b = 1; b <= 2*(n-i); b++)
        {
            printf(" ");
        }

        for (int c = i; c >= 1; c--)
        {
        printf("%d",c);
        }
        /*for (int k = 0; i < ; i++)
        {
             code
        }*/
        

    printf("\n");
    }
    
    
    
    
    
}