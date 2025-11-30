#include <stdio.h>
#include <math.h>

int main() {
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    int resultado = pow(x, 3) + pow(y, 2) + x * y * z;
    printf("%d\n", resultado);
    return 0;
}
