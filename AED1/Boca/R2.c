#include <stdio.h>
#include <stdlib.h>

int N;
int usado[9];
int perm[9];

void gerar(int k)
{
    if (k == N)
    {
        for (int i = 0; i < N; i++)
        {
            if (i > 0)
                printf(" ");
            printf("%d", perm[i]);
        }
        printf("\n");
        return;
    }

    for (int i = 1; i <= N; i++)
    {
        if (!usado[i])
        {
            usado[i] = 1;
            perm[k] = i;
            gerar(k + 1);
            usado[i] = 0;
        }
    }
}

int main()
{
    scanf("%d", &N);
    gerar(0);
    return 0;
}
