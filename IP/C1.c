#include <stdio.h>

int main (void){
    int n, soma = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", i);
        soma += i;
    }
    printf("\n%d", soma);
    return 0;
}