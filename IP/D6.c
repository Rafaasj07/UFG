#include <stdio.h>

double harmonica(int N)
{
    double S, Soma = 0;
    for (int i = 1; i <= N; i++)
    {
        S = (double)1/i;
        Soma += S;
    }
    
    return Soma;
}
int main(void)
{
    int N;
    double result;

    scanf("%d", &N);
    if (N < 1)
        return 0;
    else
    {
        result = harmonica(N);
        printf("%.4lf", result);
    }
    return 0;
}