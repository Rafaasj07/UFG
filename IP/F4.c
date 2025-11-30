#include <stdio.h>

int main(void)
{
    int n, m;
    int matriz[100][100];
    int i, j;
    int linha_ok = 1, coluna_ok = 1;

    scanf("%d %d", &n, &m);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &matriz[i][j]);
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 1; j < m; j++)
        {
            if (matriz[i][j] < matriz[i][j - 1])
            {
                linha_ok = 0;
                break;
            }
        }
        if (!linha_ok) break; // Se a primeira linha já tiver fora de ordem sai do for
    }

    // Verificação das colunas (crescentes de cima para baixo)
    for (j = 0; j < m; j++)
    {
        for (i = 1; i < n; i++)
        {
            if (matriz[i][j] < matriz[i - 1][j])
            {
                coluna_ok = 0;
                break;
            }
        }
        if (!coluna_ok) break;
    }

    // Resultado final
    if (linha_ok && coluna_ok)
        printf("SIM\n");
    else
        printf("NAO\n");

    return 0;
}
