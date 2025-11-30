#include <stdio.h>

int main(void)
{
    int N;

    scanf("%d", &N);

    if (N > 0)
    {
        int vetor[N], novo_vetor[N];

        for (int i = 0; i < N; i++)
        {
            scanf("%d", &vetor[i]);
        }

        for (int i = 0; i < N; i++)
        {
            if (N == 1)
            {
                novo_vetor[i] = 0;
            }
            else if (i == 0)
            {
                novo_vetor[i] = vetor[i + 1];
            }
            else if (i == N - 1)
            {
                novo_vetor[i] = vetor[i - 1];
            }
            else
            {
                novo_vetor[i] = vetor[i - 1] + vetor[i + 1];
            }
        }

        for (int i = 0; i < N; i++)
        {
            printf("%d ", novo_vetor[i]);
        }
    }

    return 0;
}
