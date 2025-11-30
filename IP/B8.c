#include <stdio.h>

int main (void){
    float salario, vendas;

    scanf("%f", &vendas);

    salario = 500 + (vendas * 0.09);
    if(vendas > 15000) {
        salario += 800;
        printf("%f", salario);
    }else if(vendas <= 15000)
        printf("%f", salario);
    return 0;
}