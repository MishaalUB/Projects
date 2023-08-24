#include <stdio.h>

int main(void){

    int num_people;
    int slices_per_pizza;
    int slices_each;
    int zero = 0;

    scanf("%d %d %d", &num_people, &slices_per_pizza, &slices_each);

    if (num_people > 0 && slices_per_pizza > 0 && slices_each > 0)
    {
        int num = num_people * slices_each;
        int denom = slices_per_pizza;
        int i = num/denom;
        int a = num%denom;

        /* num of slices divided by slices per pizza and rounding it up*/

        if (a == 0)
        {
            printf("%d\n",i);
        }
    
        else
        {
            i = i + 1;
            printf("%d\n", i);
        }
        
    }
    else if (num_people <=0 || slices_per_pizza <= 0 || slices_each <= 0)
    {
        printf("%d\n", zero);
    }

    return 0;   

}