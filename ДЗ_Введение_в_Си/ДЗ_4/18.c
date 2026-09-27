#include <stdio.h>

int main(int argc, char **argv){
    int s1, s2;
    scanf("%d", &s1);
    scanf("%d", &s2);
    if (s1 > s2){
        printf("Above");
    } else if (s1 < s2){
        printf("Less");
    }else{
        printf("Equal");
    }
    
    return 0;
}