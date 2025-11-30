#include <stdio.h>

int main (void){
    float N1, N2, N3, Media;
    int F;
    scanf("%f %f %f %d", &N1, &N2, &N3, &F);

    Media = (N1 + N2 + N3)/ 3;
    if(F > 16){
        printf("Reprovado por falta");
    }else if(Media >= 7){
        printf("Aprovado"); 
    }else if((Media >= 5) && (Media < 7)){
        printf("Prova final"); 
    }else if(Media < 5){
        printf("Reprovado"); 
    }
    return 0;
}

