#include <stdio.h>

int main (void){
    float P_inicial, D, Decremento_P, P_min, Lucro, LucroMax = 0, P_max = 0;
    int Q_inicial, Incremento_Q, Q_max;
    scanf("%f %d %f %f %d %f", &P_inicial, &Q_inicial, &D, &Decremento_P, &Incremento_Q, &P_min);
    
    printf("Preco Ingressos Vendidos Lucro \n");
    for (float i = P_inicial; i >= P_min; i-= Decremento_P)
    {
        Lucro = (i * Q_inicial) - D;
        if(LucroMax < Lucro){
            LucroMax = Lucro;
            P_max = i;
            Q_max = Q_inicial;
        }
        printf("%.2f         %d         %.2f \n", i,  Q_inicial, Lucro);
        Q_inicial += Incremento_Q;
        Lucro = 0;

    }
    printf("Lucro maximo: %.2f \n", LucroMax);
    printf("Na faixa de preco: %.2f com %d ingressos.\n", P_max, Q_max);
    return 0;
}