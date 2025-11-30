#include <stdio.h>

int particoes(int n, int k) {
    if (n == 0) return 1;    
    if (n < 0) return 0;      
    if (k == 0) return 0;     

    return particoes(n, k - 1) + particoes(n - k, k);
}

int main() {
    int N;
    scanf("%d", &N);

    printf("%d\n", particoes(N, N));
    return 0;
}
