#include <stdio.h>
#include <stdlib.h>

int N;
int solucoes = 0;

int pode_colocar(int tabuleiro[10][10], int linha, int coluna)
{
    int i, j;

    // verifica coluna
    for (i = 0; i < linha; i++)
    {
        if (tabuleiro[i][coluna] == 1)
        {
            return 0;
        }
    }

    // verifica diagonal superior esquerda
    for (i = linha - 1, j = coluna - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (tabuleiro[i][j] == 1)
        {
            return 0;
        }
    }

    // verifica diagonal superior direita
    for (i = linha - 1, j = coluna + 1; i >= 0 && j < N; i--, j++)
    {
        if (tabuleiro[i][j] == 1)
        {
            return 0;
        }
    }

    return 1; // pode colocar
}

void resolver(int tabuleiro[10][10], int linha)
{
    if (linha == N)
    {
        solucoes++;
        return;
    }

    for (int coluna = 0; coluna < N; coluna++)
    {
        if (pode_colocar(tabuleiro, linha, coluna))
        {
            tabuleiro[linha][coluna] = 1;   // coloca rainha
            resolver(tabuleiro, linha + 1); // chama próxima linha
            tabuleiro[linha][coluna] = 0;   // remove rainha
        }
    }
}

int main()
{
    scanf("%d", &N);

    int tabuleiro[10][10] = {0}; 
    resolver(tabuleiro, 0);

    printf("%d\n", solucoes);
    return 0;
}
