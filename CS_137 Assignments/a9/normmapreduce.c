#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>

typedef struct Vector
{
    double x, y, z;
} Vector;

void EuclideanNorm(void *src, void *dest){ // map - src = a, dest = b
    *(double *)dest = sqrt(pow(((Vector*)src)->x, 2) + pow(((Vector *)src)->y, 2) + pow(((Vector*)src)->z, 2));
}

void sum(void *src, void *dest){ // reduce - 
    *(double *)dest = *(double *)src + *(double *)dest;
}