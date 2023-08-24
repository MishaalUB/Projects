#include <stdio.h>
#include <assert.h>
#include "event.h"

int freetime (struct event schedule[], int n, int hour, int min){
    for(int i = 0; i < n; i++){
        struct event current = schedule[i];
        if(hour > current.start.hour && hour < current.end.hour) return 0;
        if(hour == current.start.hour && min >= current.start.minute){
            if(current.end.hour > current.start.hour) return 0;
            if(current.start.hour == current.end.hour && min < current.end.minute) return 0;
        }
        if(hour == current.end.hour && min < current.end.minute){
            if(current.start.hour < current.end.hour) return 0;
            if(current.start.hour == current.end.hour && min >= current.start.minute) return 0;
        }
}
return 1;
}