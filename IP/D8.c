#include <stdio.h>
int contaDivisores(int num)
{
    int divisor = 0;
    
    for (int i = 1; i <= num; i++)
    {
        if (num % i == 0)
        {
            divisor += 1;
        }
    }

    return divisor;
}

int main(void)
{
    int num, receba;
    scanf("%d", &num);
    if (num <= 0)
    return 0;
    else receba = contaDivisores(num);

    printf("%d", receba);

    return 0;
}
