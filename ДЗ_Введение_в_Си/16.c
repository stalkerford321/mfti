#include <stdio.h>
#include <string.h>

int main(int argc, char **argv){
    int s1, s2, s3;
    scanf("%d %d %d", &s1, &s2, &s3);
    if (s1 < s2 && s2 < s3){
        printf("YES");
    }else{
        printf("NO");
    }
    return 0;
}