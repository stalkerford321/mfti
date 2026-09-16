#include <stdio.h>

int main(int argc, char **argv){
    int array[4], min, max; 
    scanf("%d %d %d %d %d", &array[0], &array[1], &array[2], &array[3], &array[4]);
    min = array[0];
    max = max;
    for (int i = 0; i <= 4; i++) {
        if (min > array[i]){
            min = array[i];
        }
        if (max < array[i]){
            max = array[i];
        }
    }
    printf("%d", min + max);
    return 0;
}