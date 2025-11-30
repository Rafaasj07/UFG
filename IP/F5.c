#include <stdio.h>

int main(void)
{
    int n;
    int matriz[100][100];
    int i, j;
    int trasposta[100][100];

    scanf("%d", &n);
    if (n >= 1 && n <= 100)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                scanf("%d", &matriz[i][j]);
            }
        }

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                trasposta[j][i] = matriz[i][j];
            }
        }

        for (i = 0; i < n; i++)
        {
            for (j = n - 1; j >= 0; j--)
            {
               printf("%d ", trasposta[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}