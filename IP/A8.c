#include <stdio.h>

int main() {
    double salario_janeiro;
    scanf("%lf", &salario_janeiro);
    double salario[12];
    for(int i = 0; i < 12; i++) {
        if(i < 3) {
            salario[i] = salario_janeiro;
        } else if(i < 8) {
            salario[i] = salario_janeiro * 1.05;
        } else {
            salario[i] = salario_janeiro * 1.05 * 1.039;
        }
    }
    for(int i = 0; i < 12; i++) {
        printf("%.6lf\n", salario[i]);
    }
    return 0;
}
