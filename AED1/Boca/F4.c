#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int x;
    struct No *proximo;
} No;

typedef struct Fila
{
    No *primeiro;
    No *fim;
    int tam;
} Fila;

void criar_fila(Fila *fila)
{
    fila->primeiro = NULL;
    fila->fim = NULL;
    fila->tam = 0;
}

void enfileirar(Fila *fila, int x)
{
    No *novo = malloc(sizeof(No));
    if (novo)
    {
        novo->x = x;
        novo->proximo = NULL;
        if (fila->primeiro == NULL)
        {
            fila->primeiro = novo;
            fila->fim = novo;
        }
        else
        {
            fila->fim->proximo = novo;
            fila->fim = novo;
        }
        fila->tam++;
    }
}

long long desinfileirar(Fila *fila)
{
    if (fila->primeiro)
    {
        No *rem = fila->primeiro;
        long long valor = rem->x;
        fila->primeiro = rem->proximo;
        fila->tam--;
        if (fila->primeiro == NULL)
            fila->fim = NULL;
        free(rem);
        return valor;
    }
}

int main(void)
{
    int n, k;
    scanf("%d %d", &n, &k);

    Fila fila;
    criar_fila(&fila);

    long long soma = 0;
    for (int i = 0; i < n; i++)
    {
        long long x;
        scanf("%lld", &x);
        enfileirar(&fila, x);
        soma += x;

        if (fila.tam > k)
            soma -= desinfileirar(&fila);

        printf("%lld\n", soma);
    }
    
    return 0;
}
