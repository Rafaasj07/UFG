#include <stdio.h>
#include <math.h>

int main (void){
    float sin, A;
    scanf("%f", &A);
    for (float x = 0.0; x <= A + 0.05; x+= 0.1)//Apartir do 0.6 meu numero comeca a ser 0.6999 e aí da um bug no compilador e ele não entende que 0.699
    {                                          //é menor que 7, por estar muito proximo. Então eu dou uma folga de 0.05, aí ele vai conseguir entender que
        int sinal = -1;                        //0.699 é menor do que 0.75, dessa maineira, ele vai repetir pela 8° vez de forma correta.
        sin = x;
        for (int i = 3; i <= 7; i+= 2) 
        {                          
            float fatorial = 1;   
            for (int j = 1; j <= i; j++)
            {
                fatorial *= j; 
            }
                sin += sinal * (pow (x, i))/fatorial;
                sinal *= -1;
        }
        printf("%.1f \n", x);
        printf("%.4f \n", sin);
    }
    return 0;
}