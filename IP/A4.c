#include <stdio.h>
#include <math.h>

int main() {
    double c1, c2;
    scanf("%lf %lf", &c1, &c2);
    double hipotenusa = sqrt(c1 * c1 + c2 * c2);
    printf("%.6lf\n", hipotenusa);
    return 0;
}
