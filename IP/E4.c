#include <stdio.h>
#include <math.h>

int main(void)
{
    int N;
    float somatorio = 0;

    scanf("%d", &N);
    if (N >= 2 && N % 2 == 0)
    {
        float vetor[N];

        for (int i = 0; i < N; i++)
        {
            scanf("%f", &vetor[i]);
        }
        for (int i = 0; i < N/2; i++)
        {
            somatorio += pow(vetor[i] - vetor[N - (i + 1)], 3);
        }
        
    }
    else
    {
        return 0;
    }
    printf("%.2f", somatorio);
    return 0;
}