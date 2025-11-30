#include <stdio.h>
#include <math.h>

int main(void)
{
    int N, M;
    double matriz[100][100];
    double resultado[100];

    scanf("%d %d", &N, &M);

    // Leitura da matriz
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            scanf("%lf", &matriz[i][j]);

    // Aplicação do softmax por linha
    for (int i = 0; i < N; i++)
    {
        double somaExp = 0.0;
        double maxVal = matriz[i][0];

        // 1. Achar o maior valor da linha
        for (int j = 1; j < M; j++) {
            if (matriz[i][j] > maxVal)
                maxVal = matriz[i][j];
        }

        // 2. Calcular exp(x - max) para evitar overflow
        for (int j = 0; j < M; j++) {
            resultado[j] = exp(matriz[i][j] - maxVal);
            somaExp += resultado[j];
        }

        // 3. Dividir cada exp normalizado pela soma
        for (int k = 0; k < M; k++) {
            resultado[k] /= somaExp;
            printf("%.6lf", resultado[k]);
            if (k < M - 1) printf(" ");
        }

        printf("\n");
    }

    return 0;
}
