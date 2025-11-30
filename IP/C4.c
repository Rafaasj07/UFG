#include <stdio.h>

int main (void){
    int a;
    scanf("%d", &a);
    while (a > 0){
        int quadrado = 0;
        for (int i = 1; i <= a; i++)
        {
            if (i * i == a){
               quadrado = 1;
               break;
            }
        }   
            if (quadrado == 1){
                printf("%d eh quadrado perfeito \n", a);
            }else if(quadrado == 0){
                printf("%d nao eh quadrado perfeito \n", a);
            }
            scanf("%d", &a);
        }
        return 0;
    }
   
