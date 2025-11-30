#include <stdio.h>
#include <stdlib.h>

// Função de comparação para qsort
int cmp(const void *a, const void *b) {
    long long x = *(long long*)a;
    long long y = *(long long*)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int main() {
    int N;
    scanf("%d", &N);

    long long arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%lld", &arr[i]);
    }

    // Ordena o array
    qsort(arr, N, sizeof(long long), cmp);

    // Pega a mediana
    long long mediana = arr[N / 2];

    // Calcula a soma das distâncias
    long long soma = 0;
    for (int i = 0; i < N; i++) {
        long long diff = arr[i] - mediana;
        if (diff < 0) diff = -diff;
        soma += diff;
    }

    printf("%lld\n", soma);

    return 0;
}
