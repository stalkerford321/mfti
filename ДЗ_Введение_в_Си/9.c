#include <stdio.h>

int main(int argc, char **argv){
    int array[4], max; 
    scanf("%d %d %d %d %d", &array[0], &array[1], &array[2], &array[3], &array[4]);
    max = array[0];
    for (int i = 0; i <= 4; i++) {
        if (max < array[i]){
            max = array[i];
        }
    }
    printf("%d", max);
    return 0;
}