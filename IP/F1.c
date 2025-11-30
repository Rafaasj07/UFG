#include <stdio.h>

int main(void)
{
    int n, m;
    int matriz[100][100];
    int i, j;
    int trasposta[100][100];

    scanf("%d %d", &n, &m);
    if ((n >= 1 && n <= 100) && (m >= 1 && m <= 100))
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                scanf("%d", &matriz[i][j]);
            }
        }

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                trasposta[j][i] = matriz[i][j];
            }
        }

        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {
               printf("%d ", trasposta[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}