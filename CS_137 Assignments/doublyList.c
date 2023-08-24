#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

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
    int i;
    for(i = 1; i < n; i++){
        currentnode = currentnode->next; // will get the node to the element we want deleted
    }
    
    if(i == 1){
        lst->head = currentnode->next;
        if(currentnode->next == NULL){
            lst->tail = NULL;
        }
        else{
            currentnode->next->prev = NULL;
        }
    }
    else{
        currentnode->prev->next = currentnode->next;
        if(currentnode->next == NULL){
            lst->tail = currentnode->prev;
        }
        else{
            currentnode->next->prev = currentnode->prev;
        }
    }

    lst->len--;
    free(currentnode);
    // if(lst->len == 1){
    //     lst->head = NULL;
    //     lst->tail = NULL;
    //     lst->len--;
    //     free(currentnode);
    //     return ;
    // }
    // else if(n == 1){
    //     lst->head = currentnode->next;
    //     currentnode->next->prev = NULL;
    //     lst->len--;
    //     free(currentnode);
    //     return ;
    // }
    // else if(n == lst->len){
    //     dlnode *last = lst->tail;
    //     lst->tail = last->prev;
    //     last->prev->next = NULL;
    //     lst->len--;
    //     free(currentnode);
    //     return ;
    // }

    // currentnode->next->prev = currentnode->prev;
    // currentnode->prev->next = currentnode->next;
    // free(currentnode);
    // lst->len--;
}

void dlistAddToFront(ndlst *lst, int elem){
    dlnode *new = malloc(sizeof(dlnode));
    new->data = elem;
    new->next = lst->head;
    lst->head = new;
    if(new->next == NULL){
        lst->tail = new;
    }
    else{
        new->next->prev = new;
    }
    new->prev = NULL;
    lst->len = lst->len + 1;
}

void dlistAddToEnd(ndlst *lst, int elem){
    dlnode *new = malloc(sizeof(dlnode));
    new->data = elem;
    new->prev = lst->tail;
    lst->tail = new;
    if(new->prev == NULL){
        lst->head = new;
    }
    else{
        new->prev->next = new;
    }
    new->next = NULL;
    lst->len = lst->len + 1;
}

void dlistSort(ndlst *lst){
    dlnode *current = lst->head;
    for(; current->next; current = current->next){
        dlnode *min = current;
        dlnode *idk = current->next;
        for(; idk; idk = idk->next){ // swap the date in this loop
            if(min->data > idk->data){
                min = idk;
            }
        }
        int temp;
        temp = current->data;
        current->data = min->data;
        min->data = temp;
    }
}

void dlistRotateLeft(ndlst *lst, int n){
    
    for(int i = 1; i<=n; i++){
        int datas = lst->head->data;
        dlistRemoveElem(lst, 1);
        dlistAddToEnd(lst, datas);
    }
}

void dlistRotateRight(ndlst *lst, int n){
    
    for(int i = 1; i<=n; i++){
        int datas = lst->tail->data;
        dlistRemoveElem(lst, lst->len);
        dlistAddToFront(lst, datas);
    }
}

// void dlistPrint(ndlst *lst) // I am using this function to print
//  // results but don't submit this function
//  {
//  dlnode *node = lst->head;
//  for (; node; node = node->next)
//  printf("%d ",node->data);
//  printf("\n");
//  }

//  void dlistPrintReverse(ndlst *lst) // I am using this function to
//  // print results but don't submit this function
//  {
//  dlnode *node = lst->tail;
//  for (; node; node = node->prev)
//  printf("%d ",node->data);
//  printf("\n");
//  }

//  int main(void)
//  {
//  ndlst *lst1 = dlistCreate();
//  assert(dlistLength(lst1) == lst1->len);
//  assert(dlistLength(lst1) == 0);
//  dlistAddToEnd(lst1, 10);
//  dlistAddToFront(lst1, -20);
//  dlistAddToFront(lst1, 0);
//  dlistAddToEnd(lst1, 9);
//  dlistAddToFront(lst1, -9);
//  dlistAddToFront(lst1, 7);
//  dlistAddToEnd(lst1, 40);
//  assert(dlistLength(lst1) == lst1->len);
//  assert(dlistLength(lst1) == 7);
//  dlistPrint(lst1);
//  dlistPrintReverse(lst1);
//  dlistRemoveElem(lst1, 5);
//  dlistRemoveElem(lst1, 1);
//  dlistRemoveElem(lst1, 5);
//  dlistAddToEnd(lst1, 100);
//  assert(dlistLength(lst1) == lst1->len);
//  assert(dlistLength(lst1) == 5);
//  dlistPrint(lst1);
//  dlistPrintReverse(lst1);
//  dlistSort(lst1);
//  dlistPrint(lst1);
//  dlistRotateLeft(lst1, 2); // 0 9 100 -20 -9
//  dlistPrint(lst1);
//  dlistRotateRight(lst1, 3); // 100 -20 -9 0 9
//  dlistPrint(lst1);
//  dlistDestroy(lst1);
//  return 0;
//  }