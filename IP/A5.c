#include <stdio.h>
#include <math.h>

int main(void) {
    float h, angulo, c1, c2;

    scanf("%f %f", &h, &angulo);

    c1 = cos(angulo) * h; // cateto adjacente
    c2 = sin(angulo) * h; // cateto oposto

    printf("%f %f", c2, c1); // adjacente primeiro, depois oposto

    return 0;
}
