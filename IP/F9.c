#include <stdio.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int A[100][100];
    int F[3][3];

    // Leitura da matriz A
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            scanf("%d", &A[i][j]);

    // Leitura da matriz F (3x3)
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            scanf("%d", &F[i][j]);

    // Convolução válida
    for (int i = 1; i < N - 1; i++) {
        for (int j = 1; j < M - 1; j++) {
            int soma = 0;
            for (int di = -1; di <= 1; di++) {
                for (int dj = -1; dj <= 1; dj++) {
                    soma += A[i + di][j + dj] * F[di + 1][dj + 1];
                }
            }
            printf("%d", soma);
            if (j < M - 2) printf(" ");
        }
        printf("\n");
    }

    return 0;
}
