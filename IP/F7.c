#include <stdio.h>

int main(void)
{
    int n, m, i, j;
    float matriz[100][100];
    float maior[3] = {0, 0, 0};
    
    scanf("%d %d", &n, &m);
    if ((n >= 1 && n <= 100) && (m >= 1 && m <= 100))
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                scanf("%f", &matriz[i][j]);
                if (matriz[i][j] > maior[i])
                 {
                    maior[i] = matriz[i][j];
                 } 
            }
        }

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
               matriz[i][j] /= maior[i];
            }
        }


        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
               printf("%f ", matriz[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}