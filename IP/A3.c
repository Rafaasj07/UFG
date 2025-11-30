#include <stdio.h>
#include <math.h>

int main(void) {
    float a, b, c, d, e, x;

    scanf("%f %f %f %f %f", &a, &b, &c, &d, &e);

    x = pow(a, 3) * (((b + c) / d) + e);

    printf("%f\n", x);

    return 0;
}
