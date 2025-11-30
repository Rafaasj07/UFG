#include <stdio.h>

int main (void){
    int X, Y, Z;
    scanf("%d %d %d", &X, &Y, &Z);

    if((X + Y <= Z) || (X + Z <= Y) || (Y + Z <= X)){
        printf("Nao forma triangulo");
    }else if((X == Y) && (Y == Z)){
        printf("Equilatero"); 
    }else if((X == Y) && (Y != Z) || (X == Y) && (Y != Z) || (Y == Z) && (X != Z)){
        printf("Isosceles");
    }else if ((X != Y) && (X != Z) && (Y!= Z)){
        printf("Escaleno");
    }
    return 0;
}