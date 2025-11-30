#include <stdio.h>
#include <math.h>
#define PI 3.14159

double volumeEsfera(double raio){
    double V;
    V = (4 * PI * (pow(raio, 3))) / 3; 

    return V;
}
int main (void){
    double R, result;

    scanf("%lf", &R);
    result = volumeEsfera(R);
    printf("%.4lf", result);

    return 0;
}