#include <stdio.h>

int main(void)
{
    int N, produto_escalar = 0;

    scanf("%d", &N);

    if (N > 0)
    {
        int vetA[N], vetB[N];

        for (int i = 0; i < N; i++)
        {
            scanf("%d", &vetA[i]);
        }
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &vetB[i]);
        }

        for (int i = 0; i < N; i++)
        {
            produto_escalar += vetA[i] * vetB[i];
        }
    }
    else
    {
        return 0;
    }
    printf("%d", produto_escalar);
    return 0;
}