#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

    void reverseConcatenate(void *lhs, void *rhs){
        strcat((char *)rhs, *(char **)lhs);
    }


    void concatenate(void *lhs, void *rhs){ // src and then dest - therefore its WORDS and then ANSWER - both of which are strings
        char *new = calloc(sizeof(char), strlen(*(char **)lhs) + strlen((char *)rhs) + 1);
        strcpy(new,  *(char **)lhs);
        strcat(new, (char*) rhs);
        strcpy((char *) rhs, new);
        free(new);
    }

 // string copy, we want to define a string get every strting in the LHS char **
 // we have an array of strings, we want to get each strings in the lhs, find a replacement for the RHS
 // find a replacement for the right hand side
 // get the string 



