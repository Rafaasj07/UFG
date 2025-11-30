#include <stdio.h>
#include <math.h>
void converteTempo(int N)
{
    float hora, min, segundos;

    hora = (float)N / 3600;

    min = (hora - (int)hora) * 60;

    segundos = (min - (int)min) * 60;

    printf("%d %d %d", (int)(trunc(hora)), (int)(trunc(min)), (int)(round(segundos)));

}
int main(void)
{
    int segundos;
    scanf("%d", &segundos);
    converteTempo(segundos);
    return 0;
}