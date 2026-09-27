#include <stdio.h>

int main(int argc, char **argv){
    int s1, s2, s3;
    double sum;
    //printf("Enter num_1: ");
    scanf("%d", &s1);
    //printf("Enter num_2: ");
    scanf("%d", &s2);
    //printf("Enter num_3: ");
    scanf("%d", &s3);
    sum = (s1 + s2 + s3) / 3.0;
    printf("%.2f", sum);
    return 0;
}