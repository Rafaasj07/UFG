#include <stdio.h>

int main(void)
{
    int N;
    int distintos = 0;
    scanf("%d", &N);

    if (N >= 1)
    {
        int vetor[N];
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &vetor[i]);
        }

        for (int i = 0; i < N; i++)
        {
            int repetido = 0;
            for (int j = 0; j < i; j++)
            {
                if (vetor[i] == vetor[j])
                {
                    repetido = 1;
                    break;
                }
            }
            if (repetido == 0)
            {
                distintos++;
            }
        }
    }
    else
    {
        return 0;
    }
    
    printf("%d\n", distintos);
    return 0;
}
