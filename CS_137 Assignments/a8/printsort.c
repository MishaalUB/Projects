#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

void printsorted(char *word, int len)
{

    int a[26] = {0};
    int i = 0;
    int max = 0;

    while (word[i] != '\0')
    {
        if(word[i] >= 97 && word[i] <= 122){
        int character = word[i];
        a[character - 97]++;
        if (a[character - 97] > max)
        {
            max = a[character - 97];
        }
        }
        i++;
    }

    while (max > 0)
    {

        for (int j = 0; j <= 25; j++)
        {
            if (a[j] == max)
            {
                for (int k = 1; k <= max; k++)
                {
                    printf("%c", j + 97);
                }
            }
        }
        max--;
    }

    // if max is == 1, we just have to sort it alphabetically
}