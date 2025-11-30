#include <stdio.h>

int main (void){
    int numero_conta;
    float limite_credito, saldo_inicial, total_de_depositos, retiradas, saldo_final;
    scanf("%d %f %f %f %f", &numero_conta, &limite_credito, &saldo_inicial, &total_de_depositos, &retiradas);

    saldo_final = saldo_inicial + total_de_depositos - retiradas;

    if(saldo_final > limite_credito){
        printf("Credito excedido: %f", saldo_final);
    }else if (saldo_final <= limite_credito)
        printf("Saldo: %f", saldo_final); 

    return 0;
}