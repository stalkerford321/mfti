#include <stdio.h>

int main(int argc, char **argv){
    int s1, s2, s3, sum1, sum2;
    scanf("%d %d %d", &s1, &s2, &s3);
    sum1 = s1 + s2 + s3;
    printf("%d+%d+%d=%d\n", s1, s2, s3, sum1);
    sum2 = s1 * s2 * s3;
    printf("%d*%d*%d=%d", s1, s2, s3, sum2);
    return 0;
}