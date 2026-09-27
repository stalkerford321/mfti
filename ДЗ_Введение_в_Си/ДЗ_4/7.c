#include <stdio.h>

int main(int argc, char **argv){
    int s1, s2;
    scanf("%d", &s1);
    scanf("%d", &s2);
    if (s1 > s2){
        printf("%d %d", s2, s1);
    } else{
        printf("%d %d", s1, s2);
    }
    
    return 0;
}