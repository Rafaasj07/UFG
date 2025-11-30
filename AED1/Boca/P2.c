#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int x;
    struct No *proximo;
} No;

// Pilha
typedef struct Pilha
{
    No *topo;
    int tam;
} Pilha;

void criar_pilha(Pilha *p)
{
    p->topo = NULL;
    p->tam = 0;
}

void push(Pilha *p, int x)
{
    No *novo = malloc(sizeof(No));
    if (novo)
    {
        novo->x = x;
        novo->proximo = p->topo;
        p->topo = novo;
        p->tam++;
    }
}

No *pop(Pilha *p)
{
    if (p->topo)
    {
        No *remover = p->topo;
        p->topo = remover->proximo;
        p->tam--;
        return remover;
    }
    return NULL;
}

void limpar_pilha(Pilha *p)
{
    while (p->topo)
    {
        No *remover = pop(p);
        free(remover);
    }
}

// Fila
typedef struct Fila
{
    Pilha p1;
    Pilha p2;
} Fila;

void criar_fila(Fila *fila)
{
    criar_pilha(&fila->p1);
    criar_pilha(&fila->p2);
}

void inserir(Fila *fila, int x)
{
    push(&fila->p1, x);
}

void transformar_em_fila(Fila *fila)
{
    while (fila->p1.topo)
    {
        No *aux = pop(&fila->p1);
        push(&fila->p2, aux->x);
        free(aux);
    }
}

int remover(Fila *fila)
{
    if (!fila->p2.topo)
        transformar_em_fila(fila);

    No *rem = pop(&fila->p2);
    if (!rem)
        return -1;

    int num = rem->x;
    free(rem);
    return num;
}

void imprimir_frente(Fila *fila)
{
    if (!fila->p2.topo)
        transformar_em_fila(fila);
    if (!fila->p2.topo)
        printf("-1\n");
    else
        printf("%d\n", fila->p2.topo->x);
}

void tamanho_atual(Fila *fila)
{
    int tamanho = fila->p1.tam + fila->p2.tam;
    printf("%d\n", tamanho);
}

void limpar_fila(Fila *fila)
{

    limpar_pilha(&fila->p1);
    limpar_pilha(&fila->p2);
}

int main(void)
{
    int q;
    scanf("%d", &q);

    Fila fila;
    criar_fila(&fila);

    for (int i = 0; i < q; i++)
    {
        char op;
        scanf(" %c", &op);

        if (op == 'I')
        {
            int x;
            scanf("%d", &x);
            inserir(&fila, x);
        }
        else if (op == 'R')
            printf("%d\n", remover(&fila));
        else if (op == 'F')
            imprimir_frente(&fila);
        else if (op == 'S')
            tamanho_atual(&fila);
        else if (op == 'C')
            limpar_fila(&fila);
    }

    limpar_fila(&fila);
    return 0;
}
