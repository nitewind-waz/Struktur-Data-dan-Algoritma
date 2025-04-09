#include <stdio.h>

typedef struct
{
    int x;
    int y;
} Point;

int main(){
    Point P;
    Point *q = &P;
    
    q->x = 3;
    q->y = 5;

    printf("%d\n", P.x);
    printf("%d\n", P.y);

    return 0;
}