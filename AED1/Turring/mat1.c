#include <stdio.h>

int main(void)
{

    float vet[100];

    for (int i = 0; i < 100; i++)
        vet[i] = (float)i;

    for (int i = 0; i < 10; i++)
    {
        int posicao = i * 11;
        printf("M(%d)(%d) = %.f\n", i, i, vet[posicao]);
    }

    return 0;
}