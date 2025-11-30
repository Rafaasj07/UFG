#include <stdio.h>

int isPrimo (int num){
    int aux = 0;
    for (int i = 2; i <= num; i++)
    {
        if (num % i == 0)
            aux++;
    }
    if (aux > 1)
        aux = 0;
    return aux;
}
int main (void){
    int N, result;

    do
        scanf("%d", &N);
    while (N <= 0);
    
    result = isPrimo(N);
    if (result == 1)
        printf("PRIMO");
    else if (result == 0)
        printf("NAO PRIMO");

    return 0;
}