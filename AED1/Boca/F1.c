#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int x;
    struct No *proximo;
} No;

typedef struct Fila {
    No *primeiro;
    No *fim;
    int tam;
} Fila;

void criar_fila(Fila *fila) {
    fila->primeiro = NULL;
    fila->fim = NULL;
    fila->tam = 0;
}

void inserir_na_fila(Fila *fila, int x) {
    No *novo = malloc(sizeof(No));
    if (novo) {
        novo->x = x;
        novo->proximo = NULL;
        if (fila->primeiro == NULL) { 
            fila->primeiro = novo;
            fila->fim = novo;
        } else {
            fila->fim->proximo = novo;
            fila->fim = novo;
        }
        fila->tam++;
    }
}

No *remover(Fila *fila) {
    No *rem = NULL;
    if (fila->primeiro) {
        rem = fila->primeiro;
        fila->primeiro = rem->proximo;
        fila->tam--;
        if (fila->primeiro == NULL)
            fila->fim = NULL;   
    }
    return rem;
}

void imprimir_tudo(Fila *fila) {
    No *aux = fila->primeiro;
    if (!aux) {
        printf("\n");
        return;
    }
    while (aux) {
        printf("%d", aux->x);
        aux = aux->proximo;
        if (aux) printf(" ");
    }
    printf("\n");
}

void imprimir_inicio(Fila *fila) {
    if (fila->primeiro)
        printf("%d\n", fila->primeiro->x);
    else
        printf("-1\n");
}

void imprimir_fim(Fila *fila) {
    if (fila->fim)
        printf("%d\n", fila->fim->x);
    else
        printf("-1\n");
}

void limpar_fila(Fila *fila) {
    while (fila->primeiro) {
        No *aux = remover(fila);
        free(aux);
    }
}

int main(void) {
    int q;
    scanf("%d", &q);

    Fila fila;
    criar_fila(&fila);

    for (int i = 0; i < q; i++) {
        char op;
        scanf(" %c", &op);

        if (op == 'I') {
            int x;
            scanf("%d", &x);
            inserir_na_fila(&fila, x);
        } 
        else if (op == 'R') {
            No *r = remover(&fila);
            if (r) {
                printf("%d\n", r->x);
                free(r);
            } else {
                printf("-1\n");
            }
        } 
        else if (op == 'F') {
            imprimir_inicio(&fila);
        } 
        else if (op == 'B') {
            imprimir_fim(&fila);
        } 
        else if (op == 'S') {
            printf("%d\n", fila.tam);
        } 
        else if (op == 'C') {
            limpar_fila(&fila);
        } 
        else if (op == 'P') {
            imprimir_tudo(&fila);
        }
    }

    limpar_fila(&fila);
    return 0;
}
