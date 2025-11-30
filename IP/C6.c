#include <stdio.h>

int main (void){
    int N, totR = 0, totE = 0, totA = 0;
    float nota, media, soma, soma_media = 0, media_turma;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++){
        soma = 0;
        for(int j = 1; j <= 2; j++){
            scanf("%f", &nota);
            soma += nota; 
        }
        media = soma/2;
        soma_media += media;
            if (media <= 3){
                totR++;
                printf("Aluno %d: Reprovado\n", i);
            }else if ((media > 3) && (media < 7)){
                totE++;
                printf("Aluno %d: Exame\n", i);
            }else if (media >= 7){
                totA++;
                printf("Aluno %d: Aprovado\n", i);
            }     
    }
    media_turma = soma_media / N;
    printf("Total Aprovados: %d\n", totA);
    printf("Total Exame: %d\n", totE);
    printf("Total Reprovados: %d\n", totR);
    printf("A media da tuma eh: %.f", media_turma);
    return 0;
}