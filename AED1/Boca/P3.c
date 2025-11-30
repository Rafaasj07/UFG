#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10000

typedef struct No {
    char simbolo;
    struct No *proximo;
} No;

typedef struct Pilha {
    No *topo;
} Pilha;

void inicializar_pilha(Pilha *pilha) {
    pilha->topo = NULL;
}

void empilhar(Pilha *pilha, char simbolo) {
    No *novo = (No*) malloc(sizeof(No));
    novo->simbolo = simbolo;
    novo->proximo = pilha->topo;
    pilha->topo = novo;
}

char desempilhar(Pilha *pilha) {
    if (!pilha->topo) return '\0';
    No *remover = pilha->topo;
    char simbolo = remover->simbolo;
    pilha->topo = remover->proximo;
    free(remover);
    return simbolo;
}

char topo_pilha(Pilha *pilha) {
    if (!pilha->topo) return '\0';
    return pilha->topo->simbolo;
}

int pilha_vazia(Pilha *pilha) {
    return pilha->topo == NULL;
}

int obter_precedencia(char op) {
    switch (op) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

int eh_operador(char c) {
    return (c=='+' || c=='-' || c=='*' || c=='/' || c=='^');
}

int eh_associativo_direita(char c) {
    return (c == '^');
}

int converter_infixa_para_posfixa(char *expressao_infixa, char *expressao_posfixa) {
    Pilha operadores;
    inicializar_pilha(&operadores);

    int indice_saida = 0;
    int contador_parenteses = 0;

    for (int i = 0; expressao_infixa[i] != '\0'; i++) {
        char atual = expressao_infixa[i];

        if ((atual >= 'A' && atual <= 'Z') || (atual >= '1' && atual <= '9')) {
            expressao_posfixa[indice_saida++] = atual;
            expressao_posfixa[indice_saida++] = ' ';
        }
        else if (atual == '(') {
            empilhar(&operadores, atual);
            contador_parenteses++;
        }
        else if (atual == ')') {
            contador_parenteses--;
            if (contador_parenteses < 0) return 0; 

            while (!pilha_vazia(&operadores) && topo_pilha(&operadores) != '(') {
                expressao_posfixa[indice_saida++] = desempilhar(&operadores);
                expressao_posfixa[indice_saida++] = ' ';
            }

            if (pilha_vazia(&operadores)) return 0; 

            desempilhar(&operadores); 
        }
        else if (eh_operador(atual)) {

            while (
                !pilha_vazia(&operadores) &&
                eh_operador(topo_pilha(&operadores)) &&
                (
                    (!eh_associativo_direita(atual) &&
                     obter_precedencia(topo_pilha(&operadores)) >= obter_precedencia(atual)) ||

                    (eh_associativo_direita(atual) &&
                     obter_precedencia(topo_pilha(&operadores)) > obter_precedencia(atual))
                )
            ) {
                expressao_posfixa[indice_saida++] = desempilhar(&operadores);
                expressao_posfixa[indice_saida++] = ' ';
            }

            empilhar(&operadores, atual);
        }
        else {
            return 0;
        }
    }

    if (contador_parenteses != 0) return 0;

    while (!pilha_vazia(&operadores)) {
        if (topo_pilha(&operadores) == '(') return 0;

        expressao_posfixa[indice_saida++] = desempilhar(&operadores);
        expressao_posfixa[indice_saida++] = ' ';
    }

    expressao_posfixa[indice_saida] = '\0';
    return 1;
}

int main() {
    char linha[MAX];
    char saida[MAX];

    while (fgets(linha, MAX, stdin)) {
        linha[strcspn(linha, "\n")] = '\0';

        printf("%s\n", linha);

        if (converter_infixa_para_posfixa(linha, saida))
            printf("%s\n\n", saida);
        else
            printf("Expressao invalida\n\n");
    }

    return 0;
}
