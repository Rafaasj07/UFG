#include <stdio.h>
#include <stdlib.h>

int *alocar_tridiagonal_inversa(int m, int n)
{
    int k = (m > n) ? m : n; // máximo entre m e n
    int r = (m < n) ? m : n; // mínimo entre m e n

    int **matriz = malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++)
        matriz[i] = malloc(n * sizeof(int));

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &matriz[i][j]);

    int tamanho = 3 * r - 2;
    int *vetor = malloc(tamanho * sizeof(int));
    if (!vetor)
    {
        printf("Erro de alocação de memória!\n");
        exit(1);
    }

    int pos = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i + j >= k - 2 && i + j <= k) // elementos relevantes
            {
                vetor[pos++] = matriz[i][j];
            }
        }
    }

    // libera a matriz
    for (int i = 0; i < m; i++)
        free(matriz[i]);
    free(matriz);

    return vetor;
}

int main(void)
{
    int m, n;
    printf("Digite m e n: ");
    scanf("%d %d", &m, &n);

    int r = (m < n) ? m : n;
    int tamanho = 3 * r - 2;

    int *vetor = alocar_tridiagonal_inversa(m, n);

    printf("Vetor com os elementos da tridiagonal inversa:\n");
    for (int i = 0; i < tamanho; i++)
    {
        printf("vetor[%d] = %d\n", i, vetor[i]);
    }

    free(vetor);
    return 0;
}
