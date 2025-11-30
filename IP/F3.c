#include <stdio.h>

int main() {
    int N, M;
    int matriz[100][100];
    int resultado[100][100];
    int i, j, dx, dy;

    scanf("%d %d", &N, &M);


    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            int soma = 0;

            for (dx = -1; dx <= 1; dx++) {
                for (dy = -1; dy <= 1; dy++) {
                    if (dx == 0 && dy == 0)
                        continue;

                    int ni = i + dx;
                    int nj = j + dy;
                    if (ni >= 0 && ni < N && nj >= 0 && nj < M) {
                        soma += matriz[ni][nj];
                    }
                }
            }

            resultado[i][j] = soma;
        }
    }

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            printf("%d ", resultado[i][j]);
        }
        printf("\n");
    }

    return 0;
}
