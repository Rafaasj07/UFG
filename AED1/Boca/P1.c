#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int x;
    struct No *proximo;
} No;

typedef struct Pilha {
    No *topo;
    int tam;
} Pilha;

void criar_pilha(Pilha *p) {
    p->topo = NULL;
    p->tam = 0;
}

void push(Pilha *p, int x) {
    No *novo = malloc(sizeof(No));
    if (novo) {
        novo->x = x;
        novo->proximo = p->topo;
        p->topo = novo;
        p->tam++;
    }
}

No *pop(Pilha *p) {
    if (p->topo) {
        No *remover = p->topo;
        p->topo = remover->proximo;
        p->tam--;
        return remover;
    }
    return NULL;
}

void limpar_pilha(Pilha *p) {
    while (p->topo) {
        No *remover = pop(p);
        free(remover);
    }
}

void imprimir_tudo(Pilha *p) {
    if (!p->topo) {
        printf("\n");
        return;
    }
    No *aux = p->topo;
    while (aux) {
        printf("%d", aux->x);
        aux = aux->proximo;
        if (aux) printf(" ");
    }
    printf("\n");
}

void imprimir_topo(Pilha *p) {
    if (p->topo)
        printf("%d\n", p->topo->x);
    else
        printf("-1\n");
}

int main(void) {
    int q;
    scanf("%d", &q);

    Pilha p;
    criar_pilha(&p);

    for (int i = 0; i < q; i++) {
        char op;
        scanf(" %c", &op);

        if (op == 'I') {
            int x;
            scanf("%d", &x);
            push(&p, x);
        } 
        else if (op == 'R') {
            No *remover = pop(&p);
            if (remover) {
                printf("%d\n", remover->x);
                free(remover);
            } else {
                printf("-1\n");
            }
        } 
        else if (op == 'T') {
            imprimir_topo(&p);
        } 
        else if (op == 'S') {
            printf("%d\n", p.tam);
        } 
        else if (op == 'C') {
            limpar_pilha(&p);
        } 
        else if (op == 'P') {
            imprimir_tudo(&p);
        }
    }

    limpar_pilha(&p);
    return 0;
}
