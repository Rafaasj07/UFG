#include <stdio.h>

int verificaParidade (int num){
    int aux;
    if (num % 2 == 0)
        aux = 0;
    else 
        aux = 1;

    return aux;
}
int main (void){
    int N, result;

    scanf("%d", &N);
    result = verificaParidade(N);
    printf("%d", result);

    return 0;
}