// #include <stdio.h>
// #include <assert.h>
// #include <string.h>
// #include <stdlib.h>


// char* merge(char* s1, char* s2){
//     int s1Length = strlen(s1);
//     int s2Length = strlen(s2);
//     char* s3 = malloc(sizeof(char) * (s1Length+s2Length+2));
//     s3[s1Length + s2Length + 1] = '\0';
//     int i = 0;
//     int j = 0;
//     int k = 0;


//     while ((i < s1Length) && (j < s2Length))
//     {
//         while (s1[i] != ' ')
//         {
//             if(i >= s1Length) break;
//             s3[k] = s1[i];
//             i++;
//             k++;
//         }
        
//         if(s1[i] == ' '){
//             s3[k] = s1[i];
//             i++;
//             k++;
//         }

//         while (s2[j] != ' ')
//         {
//             if(j >= s2Length) break;
//             s3[k] = s2[j];
//             j++;
//             k++;
//         }
        
//         if(s2[j] == ' '){
//             s3[k] = s2[j];
//             j++;
//             k++;
//         }
//     }
//     printf("%d %d %d\n", i, j, k);

//     char *s = malloc(sizeof(char) * (s1Length + s2Length + 2));
//     s[s1Length + s2Length + 1] = '\0';
//     strcpy(s, s3);

//     if(i < s1Length){
//     //k++;
//     s[k] = ' ';
//     k++;
//     //i++;
//     while (i < s1Length)
//     {
//         s[k] = s1[i];
//         i++;
//         k++;
//     }
//     // s[k] = '\0';
//     free(s3);
//     }

//     if(j < s2Length){
//     //k++;
//     s[k] = ' ';
//     k++;
//     //j++;
//     while (j < s2Length)
//     {
//         s[k] = s1[j];
//         j++;
//         k++;
//     }
//     // s[k] = '\0';
//     free(s3);
//     }

//     return s;
// }


#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>


char* merge(char* s1, char* s2){
    int i = 0;
    int j = 0;
    int k = 0;
    int s1Length = strlen(s1);
    int s2Length = strlen(s2);
    int length = s1Length + s2Length + 2;

    char *s = malloc(sizeof(char) * length);
    s[length - 1] = '\0';

    while (s1[i] != '\0' && s2[j] != '\0')
    {
        while (i < s1Length)
        {
            if(s1[i] == ' '){
                s[k] = s1[i];
                k++;
                i++;
                break;
            }
            s[k] = s1[i];
            k++;
            i++;
        }

        if(i >= s1Length) break;

        while (j < s2Length)
        {
            if(s2[j] == ' '){
                s[k] = s2[j];
                k++;
                j++;
                break;
            }
            s[k] = s2[j];
            k++;
            j++;
        }  
    }

    // char *final = malloc(sizeof(char) * length);
    // final[length - 1] = '\0';
    // strcpy(final, s);
    // free(s);

    // final[k] = ' ';
    // k++;

    // while(i < s1Length){
    //     final[k] = s1[i];
    //     k++;
    //     i++;
    // }
    // while(j < s2Length){
    //     final[k] = s2[j];
    //     k++;
    //     j++;
    // }
    
    // return final;

    s[k] = ' ';
    k++;

    while(i < s1Length){
        s[k] = s1[i];
        k++;
        i++;
    }
    while(j < s2Length){
        s[k] = s2[j];
        k++;
        j++;
    }
    
    return s;

}