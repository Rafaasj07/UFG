#include <stdio.h>

double f_media(double n1, double n2) {
    return (n1 + n2) / 2;
}

char* situacao(double media, int *totR, int *totE, int *totA) {
    if (media <= 3.0) {
        (*totR)++;
        return "Reprovado";
    } else if (media < 7.0) {
        (*totE)++;
        return "Exame";
    } else {
        (*totA)++;
        return "Aprovado";
    }
}

int main(void) {
    int N, totR = 0, totE = 0, totA = 0;
    double n1, n2, media;
    char* situacao_aluno;

    scanf("%d", &N);

    for (int i = 1; i <= N; i++) {
        scanf("%lf %lf", &n1, &n2);
        media = f_media(n1, n2);
        situacao_aluno = situacao(media, &totR, &totE, &totA);
        printf("Aluno %d: %s\n", i, situacao_aluno);
    }

    printf("Total Aprovados: %d\n", totA);
    printf("Total Exame: %d\n", totE);
    printf("Total Reprovados: %d\n", totR);

    return 0;
}
