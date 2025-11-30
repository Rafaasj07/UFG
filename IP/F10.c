#include <stdio.h>

int main() {
    int linhas, colunas;
    scanf("%d %d", &linhas, &colunas);

    int matriz[100][100];

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    // Definindo os limites da espiral
    int cima = 0, baixo = linhas - 1;
    int esquerda = 0, direita = colunas - 1;

    while (cima <= baixo && esquerda <= direita) {
        // Percorre da esquerda para a direita na linha de cima
        for (int i = esquerda; i <= direita; i++) {
            printf("%d ", matriz[cima][i]);
        }
        cima++;

        // Percorre de cima para baixo na coluna da direita
        for (int i = cima; i <= baixo; i++) {
            printf("%d ", matriz[i][direita]);
        }
        direita--;

        // Se ainda sobrou linha embaixo, percorre da direita pra esquerda
        if (cima <= baixo) {
            for (int i = direita; i >= esquerda; i--) {
                printf("%d ", matriz[baixo][i]);
            }
            baixo--;
        }

        // Se ainda sobrou coluna à esquerda, percorre de baixo pra cima
        if (esquerda <= direita) {
            for (int i = baixo; i >= cima; i--) {
                printf("%d ", matriz[i][esquerda]);
            }
            esquerda++;
        }
    }

    return 0;
}
