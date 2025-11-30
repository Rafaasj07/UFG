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

int desenfileirar(Fila *f)
{
    No *tmp = f->primeiro;
    int val = tmp->x;

    f->primeiro = tmp->proximo;
    f->tam--;

    free(tmp);
    return val;
}

int main(void)
{
    Fila f;
    criar_fila(&f);

    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++)
        enfileirar(&f, i);

    while (f.tam > 1)
    {
        for (int i = 0; i < k - 1; i++)
        {
            int val = desenfileirar(&f);
            enfileirar(&f, val);
        }

        int eliminado = desenfileirar(&f);
        printf("%d", eliminado);
        if (f.tam > 1)
            printf(" ");
    }
    printf("\n%d", f.primeiro->x);

    return 0;
}
