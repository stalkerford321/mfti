#include <stdio.h>

int main(int argc, char **argv){
    int s1, s2, s3, max;
    scanf("%d %d %d", &s1, &s2, &s3);
    if (s1 > s2 && s1 > s3){
        max = s1;
    }else if (s2 > s1 && s2 > s3){
        max = s2;
    }else{
        max = s3;
    }
    printf("%d", max);
    return 0;
}