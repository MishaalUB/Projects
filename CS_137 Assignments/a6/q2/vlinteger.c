#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "vlinteger.h"

struct linteger *vlintegerCreate(void){
    struct linteger *t1 = malloc(sizeof(struct linteger));
    assert(t1);
    t1->arr = NULL;
    t1->length = 0;
    return t1;
}

void vlintegerDestroy(struct linteger *v){
    if(v){
        free(v->arr);
        free(v);
    }
}

void vlintegerRead(struct linteger *t1){
    int num = 0;
    while(scanf("%d", &num) == 1){
        int size = t1->length + 1;
        
        int *temp = malloc(sizeof(int) * size);
        assert(temp);
        for (int i = 0; i < t1->length; i++) {
            temp[i] = t1->arr[i];
        }
        temp[t1->length] = num;
        t1->length++;
        if (t1->arr != NULL){
            free(t1->arr);
        }
        t1->arr = temp;
    }
}


void vlintegerPrint(struct linteger *t1){
    printf("length=%d\n", t1->length);
    for(int i = 0; i < t1->length; i++){
        printf("%d", t1->arr[i]);
    }
    printf("\n");
}


struct linteger *vlintegerAdd(struct linteger *t1, struct linteger *t2){
    int longerLength = 0;

    if (t1->length > t2->length) {
        longerLength = t1->length;
    } else {
        longerLength = t2->length;
    }

    int *temp = malloc(sizeof(int) * longerLength);
    assert(temp);
    struct linteger *final = malloc(sizeof(struct linteger));
    assert(final);
    int tempValue = 0;
    int i = t1->length;
    int j = t2->length;
    int k = longerLength;

    while (i > 0 && j > 0) {
        tempValue += t1->arr[i-1] + t2->arr[j-1];
        temp[k - 1] = tempValue % 10;
        tempValue = tempValue / 10;
        i--;
        j--;
        k--;
    }

    while (i > 0) {
        tempValue += t1->arr[i];
        temp[k - 1] = tempValue % 10;
        tempValue /= 10;
        k--;
        i--;
    }
    while (j > 0) {
        tempValue += t2->arr[j];
        temp[k - 1] = tempValue % 10;
        tempValue /= 10;
        k--;
        j--;
    }

    if(tempValue != 0){
        final->arr = malloc((longerLength + 1) * sizeof(int));
        final->arr[0] = tempValue;
        final->length = longerLength + 1;
        for (int i = 1; i < final->length; i++)
        {
            final->arr[i] = temp[i-1];
        }
        free(temp);
    }
    else{
        final->length = longerLength;
        final->arr = temp;
    }
   
    return final;
}

struct linteger *vlintegerMult(struct linteger *t1, struct linteger *t2){

    printf("%d %d\n", t1->length, t2->length);

    int longerLength = t1->length + t2->length;

    int *temp = calloc(longerLength, sizeof(int));
    assert(temp);
    struct linteger *final = malloc(sizeof(struct linteger));
    assert(final);

    for(int i = t1->length - 1; i >= 0; i--){
        for(int j = t2->length - 1; j >= 0; j--){
            temp[i + j + 1] += t1->arr[i] * t2->arr[j];
            temp[i + j] += temp[i + j + 1] / 10;
            temp[i + j + 1] = temp[i + j + 1] % 10;
        }
    }

    int count = 0;
    for(int i = 0; i < longerLength; i++){
        if(temp[i] == 0) count++;
        else break;
    }

    if(count != 0){
        final->arr = malloc((longerLength - count) * sizeof(int));
        for(int i = 0; i < longerLength - count; i++){
            final->arr[i] = temp[i + count];
        }
        final->length = longerLength - count;
        free(temp);
    }
    else{
        final->arr = malloc(longerLength * sizeof(int));
        final->length = longerLength;
        final->arr = temp;
    }
    printf("%d", final->length);
    return final;
}

int main(void)
{
struct linteger *int1 = vlintegerCreate();
printf("Enter the digits separated by a space: \n");
vlintegerRead(int1);
vlintegerPrint(int1);
assert(int1->arr[0] !=0);
 char c;
 scanf("%c", &c);
 struct linteger *int2 = vlintegerCreate();
 printf("Enter the digits separated by a space: \n");
 vlintegerRead(int2);
 vlintegerPrint(int2);
 assert(int2->arr[0] !=0);
 scanf("%c", &c);
//  struct linteger *add = vlintegerAdd(int1, int2); // messes up here?? am i not allocating enough memory?
//  printf("addition\n");
//  vlintegerPrint(add);
//  assert(add->arr[0] !=0);
//  scanf("%c", &c);
 struct linteger *mult = vlintegerMult(int1, int2);
 printf("multiplication\n");
 vlintegerPrint(mult);
 assert(mult->arr[0] !=0);
 vlintegerDestroy(int1);
 vlintegerDestroy(int2);
//  vlintegerDestroy(add);
  vlintegerDestroy(mult);
 }