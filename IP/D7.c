#include <stdio.h>
#include <math.h>
double distancia(double X1, double Y1, double X2, double Y2)
{
    double dist;
    
    dist = sqrt(pow((X2 - X1), 2) + pow((Y2 - Y1), 2));
    
    return dist;
}
int main(void)
{
    double result, X1, Y1, X2, Y2;

    scanf("%lf %lf %lf %lf", &X1, &Y1, &X2, &Y2);
    
    result = distancia(X1, Y1, X2, Y2);
    printf("%.4lf", result);
    
    return 0;
}