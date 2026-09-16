#include <stdio.h>

int main(int argc, char **argv){
    int x1, x2, y1, y2; 
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    printf("%.2f %.2f", ((y2 - y1) / (double)(x2 - x1)), (y1 - (((y2 - y1) / (double)(x2 - x1)) * x1)));
    return 0;
}