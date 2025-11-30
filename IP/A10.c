#include <stdio.h>

int main() {
    int dias;
    scanf("%d", &dias);
    double distancia = 1.0 * 60 * 60 * 24 * dias / 1000.0;
    printf("%.6lf\n", distancia);
    return 0;
}
