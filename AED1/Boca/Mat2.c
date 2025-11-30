#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_TABELA 200003

typedef struct No
{
    long long chave;
    int valor;
    struct No *proximo;
} No;

No *tabelaHash[TAMANHO_TABELA];

unsigned int funcaoHash(long long chave)
{
    return (unsigned int)(chave % TAMANHO_TABELA);
}

void inserirOuAtualizar(long long chave, int valor)
{

    unsigned int indice = funcaoHash(chave);

    No *atual = tabelaHash[indice];

    while (atual != NULL)
    {
        if (atual->chave == chave)
        {
            atual->valor = valor;
            return;
        }
        atual = atual->proximo;
    }

    No *novoNo = (No *)malloc(sizeof(No));
    novoNo->chave = chave;
    novoNo->valor = valor;
    novoNo->proximo = tabelaHash[indice];
    tabelaHash[indice] = novoNo;
}

int buscar(long long chave)
{
    unsigned int indice = funcaoHash(chave);

    No *atual = tabelaHash[indice];

    while (atual != NULL)
    {
        if (atual->chave == chave)
        {
            return atual->valor;
        }
        atual = atual->proximo;
    }

    return 0;
}

void liberarTabela()
{
    for (int i = 0; i < TAMANHO_TABELA; i++)
    {
        No *atual = tabelaHash[i];
        while (atual != NULL)
        {
            No *temporario = atual;
            atual = atual->proximo;
            free(temporario);
        }
    }
}

int main()
{
    for (int i = 0; i < TAMANHO_TABELA; i++)
    {
        tabelaHash[i] = NULL;
    }

    int Q;
    scanf("%d", &Q);

    char operacao;
    long long i;
    int x;

    for (int k = 0; k < Q; ++k)
    {
        scanf(" %c", &operacao);

        if (operacao == 'A')
        {
            scanf("%lld %d", &i, &x);
            inserirOuAtualizar(i, x);
        }
        else if (operacao == 'C')
        {
            scanf("%lld", &i);
            printf("%d\n", buscar(i));
        }
    }
    liberarTabela();
    return 0;
}