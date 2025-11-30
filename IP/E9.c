#include <stdio.h>

int main(void)
{
    int N;

    scanf("%d", &N);

    if (N > 0)
    {
        int vetor[N], soma_vetor[N];

        for (int i = 0; i < N; i++)
        {
            scanf("%d", &vetor[i]);
            soma_vetor[i] = vetor[i];
        }
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < i; j++)
            {
                soma_vetor[i] += vetor[j];
            }
            
        }

        for (int i = 0; i < N; i++)
        {
            printf("%d ", soma_vetor[i]);
        }
    }
    else
    {
        return 0;
    }

    return 0;
}