#include <stdio.h>

int N;
int matriz[10][10];
int visitado[10][10];

int verifica(int linha, int coluna) {
    // Se saiu da matriz
    if (linha < 0 || coluna < 0 || linha >= N || coluna >= N)
        return 0;

    // Se encontrou parede ou já visitou
    if (matriz[linha][coluna] == 0 || visitado[linha][coluna] == 1)
        return 0;

    // Se chegou na saída
    if (linha == N-1 && coluna == N-1)
        return 1;

    // Marca como visitado
    visitado[linha][coluna] = 1;

    // Tenta andar nas 4 direções
    if (verifica(linha+1, coluna)) return 1; // baixo
    if (verifica(linha-1, coluna)) return 1; // cima
    if (verifica(linha, coluna+1)) return 1; // direita
    if (verifica(linha, coluna-1)) return 1; // esquerda

    return 0; // não achou caminho
}

int main() {
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &matriz[i][j]);

    printf("%d\n", verifica(0, 0));
    return 0;
}
