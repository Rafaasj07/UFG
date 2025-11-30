#include <stdio.h>

int main(void)
{
    int n, k, m;
    int matrizA[100][100];
    int matrizB[100][100];
    int matrizC[100][100];
    int i, j, l;

    scanf("%d %d %d", &n, &k, &m);
    if ((n >= 1 && n <= 100) && (k >= 1 && k <= 100) && (m >= 1 && m <= 100))
    {
        // Matriz A
        for (i = 0; i < n; i++)
            for (j = 0; j < k; j++)
                scanf("%d", &matrizA[i][j]);

        // Matriz B
        for (i = 0; i < k; i++)
            for (j = 0; j < m; j++)
                scanf("%d", &matrizB[i][j]);

        // Multiplicação de matrizes: C = A × B
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                matrizC[i][j] = 0;
                for (l = 0; l < k; l++) {
                    matrizC[i][j] += matrizA[i][l] * matrizB[l][j];
                }
                printf("%d ", matrizC[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}
