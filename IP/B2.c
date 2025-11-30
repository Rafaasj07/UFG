#include <stdio.h>

int main (void){
    int N;
    scanf("%d", &N);

    if(N % 2 == 0){
        printf("%d Par", N);
    }else if(N % 2 == 1)
        printf("%d Impar", N); 

    return 0;
}