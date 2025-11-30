#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int x;
    struct No *proximo;
} No;

// ---------------- FILA ----------------

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

No *desinfileirar(Fila *fila)
{
    No *rem = NULL;
    if (fila->primeiro)
    {
        rem = fila->primeiro;
        fila->primeiro = rem->proximo;
        fila->tam--;
        if (fila->primeiro == NULL)
            fila->fim = NULL;
    }
    return rem;
}

void limpar_fila(Fila *fila)
{
    while (fila->primeiro)
    {
        No *aux = desinfileirar(fila);
        free(aux);
    }
}

// ---------------- PILHA USANDO UMA FILA ----------------

Fila fila;

void empilhar(int x)
{
    enfileirar(&fila, x);

    for (int i = 0; i < fila.tam - 1; i++)
    {
        No *temp = desinfileirar(&fila);
        enfileirar(&fila, temp->x);
        free(temp);
    }
}

int desempilhar()
{
    if (fila.tam == 0)
        return -1;

    No *rem = desinfileirar(&fila);
    int valor = rem->x;
    free(rem);
    return valor;
}

void limpar_pilha()
{
    limpar_fila(&fila);
}

int main(void)
{
    int q;
    scanf("%d", &q);

    criar_fila(&fila);

    for (int i = 0; i < q; i++)
    {
        char op;
        scanf(" %c", &op);

        if (op == 'P')
        {
            int x;
            scanf("%d", &x);
            empilhar(x);
        }
        else if (op == 'O')
        {
            int v = desempilhar();
            printf("%d\n", v);
        }
        else if (op == 'T')
        {
            if (fila.tam == 0)
                printf("-1\n");
            else
                printf("%d\n", fila.primeiro->x);
        }
        else if (op == 'S')
        {
            printf("%d\n", fila.tam);
        }
        else if (op == 'C')
        {
            limpar_pilha();
        }
    }

    limpar_pilha();
    return 0;
}
