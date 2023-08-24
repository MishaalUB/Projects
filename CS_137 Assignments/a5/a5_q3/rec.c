#include <stdio.h>
#include <assert.h>

typedef struct Point{   //instead of writing struct Point __, we can write simply "point"
    int x, y;
} point;

typedef struct Rectangle{
    point bottomLeft;
    int width;
    int height;
} rectangle;

/*int maxRightx(rectangle rects[], int n){
    int minlength = rects[0].bottomLeft.x + rects[0].width;
    rectangle c = {{0, 0}, 0, 0};
    c.bottomLeft.x = rects[0].bottomLeft.x;
    c.bottomLeft.y = rects[0].bottomLeft.y;
    c.height = rects[0].height;
    c.width = rects[0].width;
    int a = 0;
    for(int i = 0; i < n; i++){
        if(c.bottomLeft.x > rects[i].bottomLeft.x || c.bottomLeft.x == rects[i].bottomLeft.x && c.width < rects[i].width){
            c.bottomLeft.x = rects[i].bottomLeft.x;
            a = i;
        }
    }
    return c.bottomLeft.x + rects[a].width;
}

int doesIntersect(rectangle rects[], int n){
    int cnt = 0;
    for(int i = 0; i < n; i++){
        rectangle current = rects[i];
        if(maxRightx(rects, n) <= rects[i].bottomLeft.x)
    }
}

rectangle intersection(rectangle rects[], int n){
    rectangle c = {{0, 0}, 0, 0};
    if(doesIntersect(rects, n) == 0) return c;
    c.bottomLeft.x = rects[0].bottomLeft.x;
    c.bottomLeft.y = rects[0].bottomLeft.y;
    c.height = rects[0].height;
    c.width = rects[0].width;
    for(int i = 0; i < n; i++){
        rectangle current = rects[i];
        if(c.bottomLeft.x < rects[i].bottomLeft.x) c.bottomLeft.x = rects[i].bottomLeft.x;
        if(c.bottomLeft.y < rects[i].bottomLeft.y) c.bottomLeft.y = rects[i].bottomLeft.y;
        if(c.height > rects[i].height) c.height = rects[i].height;
        if(c.width < rects[i].height) c.width = rects[i].width;
    }
    return c;
}*/

int disjoint(int a, int x, int b, int y) { // [a,a+x] and [b,b+y] are open intervals
    // if the edges of rectangles overlap, they dont count as overlapping since the intersection is 0
    return (a+x<b) || (b+y<a);
}

int cmax(int a,int b) {
    if (a<b)
        return b;
    return a;
}

int cmin(int a,int b) {
    if (a>b)
        return b;
    return a;
}

rectangle intersection(rectangle rects[], int n) {
    rectangle r1 = rects[0]; // first rectangle
    rectangle inter;

    for (int i=1;i<n;i++){
        rectangle r2 = rects[i];

        if (disjoint(r1.bottomLeft.x, r1.width, r2.bottomLeft.x, r2.width) || disjoint(r1.bottomLeft.y, r1.height, r2.bottomLeft.y, r2.height)){
            rectangle emptyRect;
            emptyRect.bottomLeft.x=0;
            emptyRect.bottomLeft.y=0;
            emptyRect.width=0;
            emptyRect.height=0;
            return emptyRect;
        }

        inter.bottomLeft.x=cmax(r1.bottomLeft.x, r2.bottomLeft.x);
        inter.bottomLeft.y=cmax(r1.bottomLeft.y, r2.bottomLeft.y);

        inter.width = cmin(r1.bottomLeft.x+r1.width, r2.bottomLeft.x+r2.width)-inter.bottomLeft.x;
        inter.height = cmin(r1.bottomLeft.y+r1.height, r2.bottomLeft.y+r2.height)-inter.bottomLeft.y;
        r1=r2;
    }

    return inter;
}