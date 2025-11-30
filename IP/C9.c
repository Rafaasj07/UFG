#include <stdio.h>
#include <math.h>

int main (void){
    float X, cosseno = 1, cos_math, sub_cos;
    int sinal = -1;
    scanf("%f", &X);
    for (int i = 2; i < 20; i+= 2)
    {
        float fatorial = 1;
        for (int j = 1; j <= i; j++)
        {
            fatorial *= j; 
        }
            cosseno += sinal * (pow (X, i))/fatorial;
            sinal *= -1;
    }
        cos_math = cos(X);
        sub_cos = cos_math - cosseno;
        printf("%.4f \n", cosseno);
        printf("%.4f \n", cos_math);
        printf("%.4f \n", sub_cos);
    return 0;
}