#include <stdio.h>

int main(void)
{
    int N;
    float soma_altura = 0, media_altura;

    scanf("%d", &N);

    if (N > 0)
    {
        float altura[N];

        for (int i = 0; i < N; i++)
        {
            scanf("%f", &altura[i]);
            soma_altura += altura[i];
        }

        media_altura = soma_altura / N;

        for (int i = 0; i < N; i++)
        {
            if (altura[i] > media_altura)
                printf("%.2f \n", altura[i]);
        }
    }
    else
    {
        return 0;
    }

    return 0;
}