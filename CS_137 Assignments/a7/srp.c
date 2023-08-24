#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int shortestRepeatingPrefix(char s[]){

    int identical = 0;
    int unique = 0;
    int length = strlen(s);
    bool flag = true;

    if(length == 0) return 0;

    for(int i = 1; i < length; i++){
        if(s[0] == s[i]) identical++;
        if(s[0] != s[i]) unique++;
    }
    if(unique == length-1) return length; // abcdef
    if(identical == length-1) return 1; // aaaa

    for(int i = 1; i < length; i++){ // kebkebo kebkebo
        if(length % i == 0){ 
            flag = true;
            for(int j = 0; j < length/i; j++){
            if(strncmp(s+(i*j), s, i) != 0){
                flag = false;
                break;
            }
        }
        }
        if(flag == true) return i;

    }

}