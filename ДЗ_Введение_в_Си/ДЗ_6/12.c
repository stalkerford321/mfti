#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

float sinus(float x) {
    double term = x;      
    double sum = term;
    int n = 1;
    while (fabs(term) >= 0.001) {
        term = -term * x * x / ((2 * n) * (2 * n + 1));
        sum += term;
        n++;
    }
    return (float)sum;
}

int main(void) {
    float deg;
    scanf("%f", &deg);
    float rad = deg * PI / 180.0;
    printf("%.3f\n", sinus(rad));
    return 0;
}