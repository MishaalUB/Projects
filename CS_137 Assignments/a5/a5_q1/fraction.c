#include <stdio.h>
#include <assert.h>
#include "fraction.h"

int gcd(int a, int b){
    int r = 0;
    while (b != 0){
        r = a%b;
        a = b;
        b = r;
    }
    return a;
}

struct fraction reduced(struct fraction a){
    int r = gcd(a.num, a.denom);
    a.num = a.num/r;
    a.denom = a.denom/r;
    if(a.num < 0 && a.denom > 0){
        a.num = -a.num;
        a.denom = -a.denom;
    }
    return a;
}

struct fraction fractionCreate(int numerator, int denominator){
    struct fraction a = {numerator, denominator};
    a = reduced(a);
    return a;
}

int get_numerator(struct fraction a){
    return a.num;
}
int get_denominator(struct fraction a){
    return a.denom;
}

struct fraction fractionMultiply(struct fraction a, struct fraction b){
    struct fraction c = {0, 0};
    a = reduced(a);
    b = reduced(b);
    c.num = a.num * b.num;
    c.denom = a.denom * b.denom;
    c = reduced(c);
    return c;
}

struct fraction fractionDivide(struct fraction a, struct fraction b){
    struct fraction c = {0, 0};
    a = reduced(a);
    b = reduced(b);
    c.num = a.num * b.denom;
    c.denom = a.denom * b.num;
    c = reduced(c);
    return c;
}

struct fraction fractionAdd(struct fraction a, struct fraction b){
    struct fraction c = {0, 0};
    a = reduced(a);
    b = reduced(b);
    c.num = (a.num*b.denom) + (b.num*a.denom);
    c.denom = a.denom * b.denom;
    c = reduced(c);
    return c;
}

struct fraction fractionSubtract(struct fraction a, struct fraction b){
    struct fraction c = {0, 0};
    a = reduced(a);
    b = reduced(b);
    c.num = (a.num*b.denom) - (b.num*a.denom);
    c.denom = a.denom * b.denom;
    c = reduced(c);
    return c;
}