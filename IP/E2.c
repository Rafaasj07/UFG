#include <stdio.h>

int main(void)
{
    int N;
    float  valor_max = -10, valor_min = 1000, normalizacao;

    scanf("%d", &N);

    if (N > 0)
    {
        float valores[N];

        for (int i = 0; i < N; i++)
        {
            scanf("%f", &valores[i]);
        }

        for (int i = 0; i < N; i++)
        {
            if (valores[i] > valor_max)
            {
                valor_max = valores[i];
            }
            
            if (valores[i] < valor_min)
            {
                valor_min = valores[i];
            }
        }

        for (int i = 0; i < N; i++)
        {
            if (valor_max == valor_min)
            {
                normalizacao = 0;
                printf("%.2f ", normalizacao);
            }else{
                normalizacao = (valores[i] - valor_min)/ (valor_max - valor_min); 
                printf("%.2f ", normalizacao);
            }
        }
        
    }
    else
    {
        return 0;
    }

    return 0;
}