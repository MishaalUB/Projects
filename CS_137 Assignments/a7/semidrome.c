// #include <stdio.h>
// #include <stdbool.h>
// #include <assert.h>
// #include <string.h>
// #include <stdlib.h>

// bool is_palindrome(char *s){
//     int half = strlen(s)/2;
//     int end = strlen(s) - 1;
//     int cnt = 0;
//     for(int i = 0; i < half; i++){
//         if(s[i] == s[end - i]) cnt++;
//     }
//     if(cnt == half) return true;
//     return false;
// }

// bool clength(char *s1, char *s, int i){
//     if(is_palindrome(s1) == true){
//         strcpy(s1, s + (strlen(s) - i));
//         int i = 0;
//         if(is_palindrome(s1) == true) return true;
//     }
//     s1[strlen(s1) - 1] = '\0';
//     if(s1[0] == '\0') return false;
//     clength(s1, s, i++);
// }

// bool is_semidrome(char *s){
//     int unique = 0;
//     int length = strlen(s);

//     for(int i = 0; i < length; i++){
//         if(s[0] != s[i]) unique++;
//     }
//     if(unique == length) return false; // if nothing is shown then it can't be a palindrome
//     if(is_palindrome(s) == true) return true;
//     if(length == 1) return false;

//     char *s1 = malloc(sizeof(char) * (length + 1));
//     strcpy(s1, s);
//     s1[length] = '\0';

//     if(clength(s1, s, 0) == true){
//         free(s1);
//         return true;
//     }
//     else{
//         free(s1);
//         return false;
//     }

// }

// #include <stdio.h>
// #include <stdbool.h>
// #include <assert.h>
// #include <string.h>
// #include <stdlib.h>

// bool is_palindrome(char *s)
// {
//     int half = strlen(s) / 2;
//     int end = strlen(s) - 1;
//     int cnt = 0;
//     for (int i = 0; i < half; i++)
//     {
//         if (s[i] == s[end - i])
//             cnt++;
//     }
//     if (cnt == half)
//         return true;
//     return false;
// }

// bool clength(char s1[], char *s, int i)
// {
//     if (is_palindrome(s1) == true)
//     {
//         strcpy(s1, s + (strlen(s) - i));
//         i = 0;

//         if (is_palindrome(s1) == true){ //&& strlen(s1) >= 2
//             return true;
//         }
//         else if(strlen(s1) == 1) return false;
//     }
//     s1[strlen(s1) - 1] = '\0';
//     if (s1[1] == '\0')
//         return false;
//     clength(s1, s, i+1);
// }

// bool is_semidrome(char *s)
// {
//     int unique = 0;
//     int length = strlen(s);

//     if(length <= 1) return false;

//     for (int i = 1; i < length; i++)
//     {
//         if (s[0] != s[i])
//             unique++;
//     }
//     if (unique == length - 1)
//         return false; // if nothing is shown then it can't be a palindrome
//     if (is_palindrome(s) == true)
//         return true;
//     if (length == 1)
//         return false;
//     if (length == 2)
//     {
//         if (s[0] == s[1])
//             return true;
//         else
//             return false;
//     }
//     if (length == 3)
//     {
//         if (s[0] == s[2])
//             return true;
//         else
//             return false;
//     }

//     char s1[length + 1];
//     strcpy(s1, s);
//     s1[length] = '\0';

//     if (clength(s1, s, 0) == true)
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }

//

#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

bool is_palindrome(char *s, int first, int end)
{
    if (end == first)
        return false;
    if (end == first +1){
        if(s[end] == s[first]) return true;
        else return false;
    }
    int j = end;
    for (int i = first; i < end; i++)
    {
        if(s[i] != s[j]) return false;
        j--;
    }
    return true;
}

bool helper(char *s, int i)
{
    if(!s) return false;
    int length = strlen(s);
    if (length <= 1)
        return false;
    if (is_palindrome(s, i, length - 1))
        return true;

    int j = i+1;

    while(j < length){
        if (is_palindrome(s, i, j))
        {
            if (helper(s, j + 1))
            {
                return true;
            }
        }
        j++;
    }

    return false;
}

bool is_semidrome(char *s)
{
    return helper(s, 0);
}
