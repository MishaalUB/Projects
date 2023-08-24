#ifndef VLINTEGER_H
#define VLINTEGER_H

struct linteger{
    int length;
    int *arr;
};

struct linteger *vlintegerCreate(void);

void vlintegerDestroy(struct linteger *v);

void vlintegerRead(struct linteger *t1);

void vlintegerPrint(struct linteger *t1);

struct linteger *vlintegerAdd(struct linteger *t1, struct linteger *t2);

struct linteger *vlintegerMult(struct linteger *t1, struct linteger *t2);

#endif