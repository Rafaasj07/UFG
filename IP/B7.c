#include <stdio.h>

int main (void){
    int N1, N2, N3;
    scanf("%d %d %d", &N1, &N2, &N3);

    //Casos Diferentes
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
    }else
    return 0;
}
