#include <stdio.h>

int main(void)
{
    int N, verif = 0;;
    scanf("%d", &N);
    if (N > 0)
    {
        int vetor[N];
        int j = 0;
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &vetor[i]);
        }

        if (N % 2 == 1)
        {
        for (int i = N-1; i > (N/2); i--)
        {
            if (vetor[i] != vetor[j])
            {
                verif = 1;
            }
            j++;
        }

        }else if (N % 2 == 0)
        {
            for (int i = N-1; i > (N/2 - 1); i--)
        {
            if (vetor[i] != vetor[j])
            {
                verif = 1;
            }
            j++;
        }
        }
        
        
    }
    else
    {
        return 0;
    }

    if (verif == 0)
    {
        printf("SIM");
    }
    else if (verif == 1)
    {
        printf("NAO");
    }

    return 0;
}