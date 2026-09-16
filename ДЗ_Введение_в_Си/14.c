#include <stdio.h>

// int max_min(int n, int array[n], int m){
//     int min = array[0];
//     int max = max;
//     for (int i = 0; i <= 4; i++) {
//         if (min > array[i]){
//             min = array[i];
//         }
//         if (max < array[i]){
//             max = array[i];
//         }
//     }
//     if (m){
//         return max;
//     } else {
//         return min;
//     }
// }

int main(int argc, char **argv){
    int s, s1, s2, s3, max; 
    scanf("%d", &s);
    // mas[0] = s / 100;
    // mas[1] = (s / 10) % 10;
    // mas[2] = s % 10;
    s1 = s / 100;
    s2 = (s / 10) % 10;
    s3 = s % 10;
    if (s1 > s2 && s1 > s3){
        max = s1;
    }else if (s2 > s1 && s2 > s3){
        max = s2;
    }else{
        max = s3;
    }
    // printf("%d", max_min(2, mas, 1));
    printf("%d", max);
    return 0;
}