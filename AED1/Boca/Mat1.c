#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);

    if (n % 2 == 0)
        return 0;

    int m[n][n];

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            m[i][j] = 0;

    int i = 0;
    int j = n / 2;

    for (int num = 1; num <= n * n; num++)
    {
        m[i][j] = num;

        int li = (i - 1 + n) % n; // Próxima linha (acima)
        int cj = (j - 1 + n) % n; // Próxima coluna (à esquerda)

        // Verifica se a posição candidata já está ocupada.
        if (m[li][cj] != 0)
        {
            // Se estiver ocupada, a regra é descer uma linha a partir da posição atual.
            i = (i + 1) % n;
        }
        else
        {
            // Se estiver livre, move-se para a posição candidata (para cima e à esquerda).
            i = li;
            j = cj;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (j)
                printf(" ");
            printf("%d", m[i][j]);
        }
        printf("\n");
    }

    return 0;
}