#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int m, n;

    printf("Digite as dimensoes da matriz: ");
    scanf("%d %d", &m, &n);

    // Aloca vetor de ponteiros (cada ponteiro será uma linha)
    int **matriz = malloc(m * sizeof(int *));
    // Aloca cada linha com n elementos
    for (int i = 0; i < m; i++)
        matriz[i] = malloc(n * sizeof(int));

    // Preenche a matriz
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &matriz[i][j]);

    // Troca primeira linha com penúltima
    int *aux = matriz[0];
    matriz[0] = matriz[m - 2];
    matriz[m - 2] = aux;

    // Imprime matriz
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", matriz[i][j]);
        printf("\n");
    }

    // Libera memória
    for (int i = 0; i < m; i++)
        free(matriz[i]);
    free(matriz);

    return 0;
}
