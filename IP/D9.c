#include <stdio.h>

void ordemCrescente (int N1, int N2, int N3){

    if((N1 > N2) && (N1 > N3) && (N2 > N3)){
        printf("%d %d %d", N3, N2, N1);
    }else
    if((N1 > N2) && (N1 > N3) && (N3 > N2)){
        printf("%d %d %d", N2, N3, N1);
    }else
    if((N2 > N1) && (N2 > N3) && (N1 > N3)){
        printf("%d %d %d", N3, N1, N2);
    }else
    if((N2 > N1) && (N2 > N3) && (N3 > N1)){
        printf("%d %d %d", N1, N3, N2);
    }else
    if((N3 > N1) && (N3 > N2) && (N1 > N2)){
        printf("%d %d %d", N2, N1, N3);
    }else
    if((N3 > N1) && (N3 > N2) && (N2 > N1)){
        printf("%d %d %d", N1, N2, N3);
    }else

    //Casos 2 iguais
    if((N1 == N2) && (N1 > N3)){
        printf("%d %d %d", N3, N1, N2);
    }else
    if((N1 == N3) && (N1 > N2)){
        printf("%d %d %d", N2, N1, N3);
    }else
    if((N2 == N3) && (N2 > N1)){
        printf("%d %d %d", N1, N2, N3);
    }else

    //Casos 3 iguais
    if((N1 == N2) && (N1 == N3)){
        printf("%d %d %d", N1, N2, N3);
    }
}
int main (void){
    int N1, N2, N3;

    scanf("%d %d %d", &N1, &N2, &N3);
    ordemCrescente(N1, N2, N3);

    return 0;
}