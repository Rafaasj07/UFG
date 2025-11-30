#include <stdio.h>

int main() {
    int m = 5, n = 5;
    int A[5][5] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11,12,13,14,15},
        {16,17,18,19,20},
        {21,22,23,24,25}
    };

    // 1) Contar quantos elementos abaixo da diagonal secundária
    int count = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (i + j > n - 1) count++;
        
    // 2) Criar vetor
    int V[count], k = 0;

    // 3) Preencher vetor
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i + j > n - 1) {
                V[k++] = A[i][j];
            }
        }
    }

    // 4) Mostrar vetor
    printf("Vetor:\n");
    for (int x = 0; x < count; x++) {
        printf("%d ", V[x]);
    }
    printf("\n");

    return 0;
}
