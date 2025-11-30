#include <stdio.h>

int main (void){
    int l, r, qtde = 0, media = 0, soma = 0;
    
    scanf("%d %d", &l, &r);
    if ((l == r) && (l % 2 == 1)){
       printf("%d \n", soma);
       printf("%d", media);
    }else{
    for (l; l <= r; l++){
        if (l % 2 == 0){
                qtde ++;
                soma += l;
        }
    }
    media = soma/ qtde;
    printf("%d \n", soma);
    printf("%d", media);
}
    return 0;
}