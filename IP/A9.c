#include <stdio.h>

int main() {
    int dias_faltados;
    scanf("%d", &dias_faltados);
    int limite_faltas = (128 * 0.25) / 2;
    int dias_restantes = limite_faltas - dias_faltados;
    if(dias_restantes < 0)
        dias_restantes = 0;
    printf("%d\n", dias_restantes);
    return 0;
}
