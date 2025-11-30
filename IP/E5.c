#include <stdio.h>

int main(void)
{
    int N;
    int consecutivo = 1, maior = 1;
    scanf("%d", &N);

    if (N >= 1)
    {
        int vetor[N];
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &vetor[i]);
        }

        for (int i = 0; i < N - 1; i++)
        {
            if (vetor[i] < vetor[i + 1])
            {
                consecutivo++;
                if (consecutivo > maior)
                {
                    maior = consecutivo;
                }
            }
            else
            {
                consecutivo = 1;
            }
        }

        printf("%d\n", maior);
    }
    else
    {
        return 0;
    }

    return 0;
}
