#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;

    printf("Digite a dimencao n: ");
    scanf("%d", &n);

    int **matriz = malloc(n * sizeof(int *));

    for (int i = 0; i < n; i++)
        matriz[i] = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &matriz[i][j]);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", matriz[i][j]); 
        printf("\n");
    }

    for (int i = 0; i < n; i++)
        free(matriz[i]);
    free(matriz);

    return 0;
}
