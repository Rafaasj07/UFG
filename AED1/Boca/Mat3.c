#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int k;
    scanf("%d", &k);

    int S[k];
    long long produto = 1;

    for (int i = 0; i < k; i++)
    {
        scanf("%d", &S[i]);
        produto *= S[i];
    }

    long long *matriz = malloc(produto * sizeof(long long));
    if (!matriz)
        return 1;

    for (long long i = 0; i < produto; i++)
        scanf("%lld", &matriz[i]);

    int Q;
    scanf("%d", &Q);

    for (int i = 0; i < Q; i++)
    {
        char operacao;
        scanf(" %c", &operacao);

        int qual_indice[k];
        for (int j = 0; j < k; j++)
            scanf("%d", &qual_indice[j]);

        long long valor;
        scanf("%lld", &valor);

        long long indice = 0;
        for (int j = 0; j < k; j++)
            indice = indice * S[j] + qual_indice[j];

        if (indice < produto)
            matriz[indice] = valor;
    }

    for (long long i = 0; i < produto; i++)
    {
        printf("%lld ", matriz[i]);
        if ((i + 1) % S[k - 1] == 0)
            printf("\n");
    }

    free(matriz);
    return 0;
}