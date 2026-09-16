#include <stdio.h>

int main(int argc, char **argv){
    int s; 
    scanf("%d", &s);
    printf("%d", (s / 100 + ((s / 10) % 10) + s % 10));
    return 0;
}