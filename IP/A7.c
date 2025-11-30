#include <stdio.h>

int main() {
    int c, h, l;
    scanf("%d %d %d", &c, &h, &l);
    double volume = c * h * l * 0.9;
    printf("%.6lf\n", volume);
    return 0;
}
