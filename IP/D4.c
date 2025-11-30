#include <stdio.h>
int isQuadradoPerfeito(int a)
{
    int quadrado = 0;
    
    for (int i = 1; i <= a; i++)
    {
        if (i * i == a)
        {
            quadrado = 1;
            break;
        }
    }

    return quadrado;
}

int main(void)
{
    int num, receba;
    scanf("%d", &num);
    if (num <= 0)
    return 0;
    else receba = isQuadradoPerfeito(num);

    if (receba == 1)
        printf("QUADRADO PERFEITO");
    else if (receba == 0)
        printf("NAO EH QUADRADO PERFEITO");

    return 0;
}
