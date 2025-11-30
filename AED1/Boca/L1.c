#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int valor;
    struct no *proximo;
} No;

typedef struct
{
    No *inicio;
    int tam;
} Lista;

void criar_lista(Lista *lista)
{
    lista->inicio = NULL;
    lista->tam = 0;
}

void limpar_lista(Lista *lista)
{
    No *aux = lista->inicio;
    while (aux)
    {
        No *tmp = aux->proximo;
        free(aux);
        aux = tmp;
    }
    lista->inicio = NULL;
    lista->tam = 0;
}

void inserir(Lista *lista, int p, int x)
{
    if (p < 0 || p > lista->tam)
    {
        printf("-1\n");
        return;
    }

    No *novo = malloc(sizeof(No));
    novo->valor = x;

    if (p == 0)
    {
        novo->proximo = lista->inicio;
        lista->inicio = novo;
    }
    else
    {
        No *aux = lista->inicio;
        for (int i = 0; i < p - 1; i++)
            aux = aux->proximo;

        novo->proximo = aux->proximo;
        aux->proximo = novo;
    }

    lista->tam++;
}

void remover(Lista *lista, int p)
{
    if (p < 0 || p >= lista->tam)
    {
        printf("-1\n");
        return;
    }

    No *remover;
    if (p == 0)
    {
        remover = lista->inicio;
        lista->inicio = remover->proximo;
    }
    else
    {
        No *aux = lista->inicio;
        for (int i = 0; i < p - 1; i++)
            aux = aux->proximo;
        remover = aux->proximo;
        aux->proximo = remover->proximo;
    }

    free(remover);
    lista->tam--;
}

void imprimir_posicao(Lista *lista, int p)
{
    if (p < 0 || p >= lista->tam)
    {
        printf("-1\n");
        return;
    }

    No *aux = lista->inicio;
    for (int i = 0; i < p; i++)
        aux = aux->proximo;

    printf("%d\n", aux->valor);
}

void imprimir_tudo(Lista *lista)
{
    No *aux = lista->inicio;
    while (aux)
    {
        printf("%d ", aux->valor);
        aux = aux->proximo;
    }
    printf("\n");
}

void tamanho_atual(Lista *lista)
{
    printf("%d\n", lista->tam);
}

int main()
{
    int q;
    scanf("%d", &q);

    Lista lista;
    criar_lista(&lista);

    for (int i = 0; i < q; i++)
    {
        char op;
        scanf(" %c", &op);

        if (op == 'I')
        {
            int p, x;
            scanf("%d %d", &p, &x);
            inserir(&lista, p, x);
        }
        else if (op == 'R')
        {
            int p;
            scanf("%d", &p);
            remover(&lista, p);
        }
        else if (op == 'G')
        {
            int p;
            scanf("%d", &p);
            imprimir_posicao(&lista, p);
        }
        else if (op == 'T')
        {
            tamanho_atual(&lista);
        }
        else if (op == 'P')
        {
            imprimir_tudo(&lista);
        }
    }

    limpar_lista(&lista);
    return 0;
}
