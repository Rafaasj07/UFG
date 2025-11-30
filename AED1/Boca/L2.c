#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *ant;
    struct no *prox;
} No;

typedef struct {
    No *inicio;
    No *fim;
    int tam;
} Lista;

void criar_lista(Lista *lista) {
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tam = 0;
}

void limpar_lista(Lista *lista) {
    No *aux = lista->inicio;
    while (aux) {
        No *tmp = aux->prox;
        free(aux);
        aux = tmp;
    }
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tam = 0;
}

void inserir(Lista *lista, int p, int x) {
    if (p < 0 || p > lista->tam) {
        printf("-1\n");
        return;
    }

    No *novo = malloc(sizeof(No));
    novo->valor = x;
    novo->ant = NULL;
    novo->prox = NULL;

    if (lista->tam == 0) {
        lista->inicio = novo;
        lista->fim = novo;
    }
    else if (p == 0) {  
        novo->prox = lista->inicio;
        lista->inicio->ant = novo;
        lista->inicio = novo;
    }
    else if (p == lista->tam) {  
        novo->ant = lista->fim;
        lista->fim->prox = novo;
        lista->fim = novo;
    }
    else {  
        No *aux = lista->inicio;
        for (int i = 0; i < p; i++)
            aux = aux->prox;

        novo->prox = aux;
        novo->ant = aux->ant;
        aux->ant->prox = novo;
        aux->ant = novo;
    }

    lista->tam++;
}

void remover(Lista *lista, int p) {
    if (p < 0 || p >= lista->tam) {
        printf("-1\n");
        return;
    }

    No *rem;

    if (lista->tam == 1) {  
        rem = lista->inicio;
        lista->inicio = NULL;
        lista->fim = NULL;
    }
    else if (p == 0) {  
        rem = lista->inicio;
        lista->inicio = rem->prox;
        lista->inicio->ant = NULL;
    }
    else if (p == lista->tam - 1) {  
        rem = lista->fim;
        lista->fim = rem->ant;
        lista->fim->prox = NULL;
    }
    else {  
        rem = lista->inicio;
        for (int i = 0; i < p; i++)
            rem = rem->prox;

        rem->ant->prox = rem->prox;
        rem->prox->ant = rem->ant;
    }

    free(rem);
    lista->tam--;
}

void imprimir_posicao(Lista *lista, int p) {
    if (p < 0 || p >= lista->tam) {
        printf("-1\n");
        return;
    }

    No *aux = lista->inicio;
    for (int i = 0; i < p; i++)
        aux = aux->prox;

    printf("%d\n", aux->valor);
}

void imprimir_esq_dir(Lista *lista) { 
    No *aux = lista->inicio;
    while (aux) {
        printf("%d ", aux->valor);
        aux = aux->prox;
    }
    printf("\n");
}

void imprimir_dir_esq(Lista *lista) { 
    No *aux = lista->fim;
    while (aux) {
        printf("%d ", aux->valor);
        aux = aux->ant;
    }
    printf("\n");
}

void tamanho_atual(Lista *lista) {
    printf("%d\n", lista->tam);
}

int main() {
    int q;
    scanf("%d", &q);

    Lista lista;
    criar_lista(&lista);

    for (int i = 0; i < q; i++) {
        char op[3];
        scanf("%s", op);

        if (op[0] == 'I') {
            int p, x;
            scanf("%d %d", &p, &x);
            inserir(&lista, p, x);
        }
        else if (op[0] == 'R') {
            int p;
            scanf("%d", &p);
            remover(&lista, p);
        }
        else if (op[0] == 'G') {
            int p;
            scanf("%d", &p);
            imprimir_posicao(&lista, p);
        }
        else if (op[0] == 'T') {
            tamanho_atual(&lista);
        }
        else if (op[0] == 'P' && op[1] == 'L') {
            imprimir_esq_dir(&lista);
        }
        else if (op[0] == 'P' && op[1] == 'R') {
            imprimir_dir_esq(&lista);
        }
    }

    limpar_lista(&lista);
    return 0;
}
