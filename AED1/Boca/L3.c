#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int valor;
    struct no *ant;
    struct no *prox;
} No;

typedef struct
{
    No *inicio;
    No *fim;
    int tam;
} Lista;

void criar_lista(Lista *lista)
{
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tam = 0;
}

void limpar_lista(Lista *lista)
{
    No *aux = lista->inicio;
    while (aux)
    {
        No *tmp = aux->prox;
        free(aux);
        aux = tmp;
    }
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tam = 0;
}

void inserir(Lista *lista, int x)
{
    No *novo = malloc(sizeof(No));
    novo->valor = x;
    novo->ant = NULL;
    novo->prox = NULL;

    if (lista->tam == 0)
    {
        lista->inicio = novo;
        lista->fim = novo;
    }
    else
    {
        novo->prox = lista->inicio;
        lista->inicio->ant = novo;
        lista->inicio = novo;
    }

    lista->tam++;
}

void bubble_sort(Lista *lista)
{
    if (lista->tam < 2)
        return;

    int trocou;
    do
    {
        trocou = 0;
        No *aux = lista->inicio;
        while (aux->prox != NULL)
        {
            if (aux->valor > aux->prox->valor)
            {
                int tmp = aux->valor;
                aux->valor = aux->prox->valor;
                aux->prox->valor = tmp;
                trocou = 1;
            }
            aux = aux->prox;
        }
    } while (trocou);
}

void imprimir_esq_dir(Lista *lista) { 
    No *aux = lista->inicio;
    while (aux) {
        printf("%d ", aux->valor);
        aux = aux->prox;
    }
    printf("\n");
}

int main()
{
    int N;
    scanf("%d", &N);

    Lista lista;
    criar_lista(&lista);

    for (int i = 0; i < N; i++)
    {
        int x;
        scanf("%d", &x);
        inserir(&lista, x);
    }

    bubble_sort(&lista);
    imprimir_esq_dir(&lista);
    limpar_lista(&lista);
    return 0;
}
