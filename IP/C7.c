#include <stdio.h>
#include <math.h>

int main (void){
    float X, soma;
    scanf("%f", &X);
    soma = X;
    for (int i = 1; i < 20; i++)
    {
        float fatorial = 1;
        for (int j = 1; j <= i; j++)
        {
            fatorial *= j; 
        }
        
        if(i % 2 == 0){
            soma += (pow(X, i))/fatorial;
        }
        else {
            soma -= (pow (X, i))/fatorial;
        }
    }
    if (soma > 1)
    {
        printf("%.5f", soma);
    }else if (soma < 1 && soma != 0)
    {
        printf("%.6f", soma);
    }else if(soma == 0){
        printf("%.f", soma);
    }
    return 0;
}