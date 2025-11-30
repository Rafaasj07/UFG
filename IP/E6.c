#include <stdio.h>

void bubble_sort(int vetor[], int n)
{
    int k, j, aux;

    for (k = 1; k < n; k++)
    {
        for (j = 0; j < n - 1; j++)
        {
            if (vetor[j] > vetor[j + 1])
            {
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
}

int main(void)
{
    int N;
    scanf("%d", &N);

    if (N >= 1)
    {
        int vetor_organizado[N], vetor_original[N];
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &vetor_original[i]);
            vetor_organizado[i] = vetor_original[i];
        }

        bubble_sort(vetor_organizado, N);
        for (int i = 0; i < N; i++)
        {
            printf("%d ", vetor_organizado[i]);
        }
    }
    else
    {
        return 0;
    }
    return 0;
}