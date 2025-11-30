#include <stdio.h>
#include <math.h>

int main (void){
    float A, B, C, DELTA, X1, X2;
    scanf("%f %f %f", &A, &B, &C);

    DELTA = pow(B, 2) - (4 * A * C);

    if (A == 0){
        printf("Nao e equacao do segundo grau");
    } else if (DELTA >= 0){
        X1 = (-B + sqrt(DELTA)) / (2 * A);
        X2 = (-B - sqrt(DELTA)) / (2 * A);
        printf("%f %f", X1, X2);
    } else if (DELTA < 0) {
        printf("Nao ha raizes reais");
    }

    return 0;
}