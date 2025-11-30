#include <stdio.h>

int main() {
    double x;
    scanf("%lf", &x);
    double reais = x * 5.05;
    printf("%.6lf\n", reais);
    return 0;
}
