#include <stdio.h>
#include <stdlib.h>

typedef struct dlnode{
    int data;
    struct dlnode *next;
    struct dlnode *prev;
} dlnode;

typedef struct ndlst{
    dlnode *head;
    dlnode *tail;
    int len;
} ndlst;

struct ndlst *dlistCreate(void){
    ndlst *ret = malloc(sizeof(ndlst));
    ret->head = NULL;
    ret->tail = NULL;
    ret->len = 0;
    return ret;
}

void dlistDestroy(ndlst *lst){
    dlnode *nextnode = lst->head;
    dlnode *currentnode = NULL;
    while(nextnode){
        currentnode = nextnode;
        nextnode = nextnode->next;
        free(currentnode);
    }
    free(lst);
}

int dlistLength(ndlst *lst){
    return lst->len;
}

void dlistRemoveElem(ndlst *lst, int n){
    dlnode *currentnode = lst->head;
    for(int i = 1; i < n; i++){
        currentnode = currentnode->next; // will get the node to the element we want deleted
    }
    dlnode *before = currentnode->prev; // (3) cases. What happens if length = 1, if n == 1, if n == len
    dlnode *after = currentnode->next;
    before->next = after;
    after->prev = before;
    lst->len--;
    free(currentnode);
}

void dlistAddToFront(ndlst *lst, int elem){
    dlnode *new = malloc(sizeof(dlnode));
    dlnode *current = lst->head;
    new->data = elem;
    new->next = current;
    new->prev = lst;
    lst->head = new;
    current->prev = new;
    lst->len++;
}

void dlistAddToEnd(ndlst *lst, int elem){
    dlnode *new = malloc(sizeof(dlnode));
    dlnode *final = lst->tail;
    new->data = elem;
    new->prev = final;
    new->next = lst;
    lst->tail = new;
    final->next = new;
    lst->len++;
}

void swap(dlnode *min, dlnode *current){ // helper function
    int temp;
    temp = min->data;
    min->data = current->data;
    current->data = temp;
}

void dlistSort(ndlst *lst){
    dlnode *min = lst->head;
    dlnode *current = lst->head;
    for(int i = 1; i <= lst->len; i++){
        for(int j = i; j < lst->len; j++){ // swap the date in this loop
        current = current->next;
            if(min->data > current->data){
                swap(min, current);
            }
        }
        min = min->next;
    }
}

void dlistRotateLeft(ndlst *lst, int n){
    if(n == 0){
        return ;
    }
    dlnode *current = lst->head;
    dlistAddToEnd(lst, current->data);
    dlistRemoveElem(lst, 1);
    dlistRotateLeft(lst, n--);
}

void dlistRotateRight(ndlst *lst, int n){
    if(n == 0){
        return ;
    }
    dlnode *current = lst->tail;
    dlistAddToFront(lst, current->data);
    dlistRemoveElem(lst, lst->len);
    dlistRotateRight(lst, n--);
}

void dlistPrint(ndlst *lst) // I am using this function to print
 // results but don't submit this function
 {
 dlnode *node = lst->head;
 for (; node; node = node->next)
 printf("%d ",node->data);
 printf("\n");
 }

 void dlistPrintReverse(ndlst *lst) // I am using this function to
 // print results but don't submit this function
 {
 dlnode *node = lst->tail;
 for (; node; node = node->prev)
 printf("%d ",node->data);
 printf("\n");
 }

 int main(void)
 {
 ndlst *lst1 = dlistCreate();
 assert(dlistLength(lst1) == lst1->len);
 assert(dlistLength(lst1) == 0);
 dlistAddToEnd(lst1, 10);
 dlistAddToFront(lst1, -20);
 dlistAddToFront(lst1, 0);
 dlistAddToEnd(lst1, 9);
 dlistAddToFront(lst1, -9);
 dlistAddToFront(lst1, 7);
 dlistAddToEnd(lst1, 40);
 assert(dlistLength(lst1) == lst1->len);
 assert(dlistLength(lst1) == 7);
 dlistPrint(lst1);
 dlistPrintReverse(lst1);
 dlistRemoveElem(lst1, 5);
 dlistRemoveElem(lst1, 1);
 dlistRemoveElem(lst1, 5);
 dlistAddToEnd(lst1, 100);
 assert(dlistLength(lst1) == lst1->len);
 assert(dlistLength(lst1) == 5);
 dlistPrint(lst1);
 dlistPrintReverse(lst1);
 dlistSort(lst1);
 dlistPrint(lst1);
 dlistRotateLeft(lst1, 2);
 dlistPrint(lst1);
 dlistRotateRight(lst1, 3);
 dlistPrint(lst1);
 dlistDestroy(lst1);
 return 0;
 }