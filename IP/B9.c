#include <stdio.h>

int main (void){
    float peso, altura, IMC;

    scanf("%f %f", &peso, &altura);

    IMC = peso / (altura * altura);
   
    if(IMC < 18.5)
        printf("Abaixo do peso");
    else if((IMC >= 18.5) && (IMC < 25))
        printf("Peso normal");
    else if((IMC >= 25) && (IMC < 30))
        printf("Sobrepeso");
    else if(IMC > 30)
        printf("Obesidade");
    return 0;
}