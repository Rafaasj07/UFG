#include <stdio.h>

#define MAXN 1000

int N, Q;
int A[MAXN][MAXN];

int saddlebackSearch(int x) {
    int i = 0, j = N - 1; // começa no canto superior direito
    while (i < N && j >= 0) {
        if (A[i][j] == x)
            return 1;
        else if (x < A[i][j])
            j--; // anda para a esquerda
        else
            i++; // anda para baixo
    }
    return 0; // não encontrado
}

int main() {
    scanf("%d %d", &N, &Q);

    // lê matriz N x N
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // processa consultas
    for (int k = 0; k < Q; k++) {
        int x;
        scanf("%d", &x);
        printf("%d\n", saddlebackSearch(x));
    }

    return 0;
}
