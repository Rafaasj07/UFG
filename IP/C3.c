#include <stdio.h>

int main (void){
    int b, e, aux = 0;
    scanf("%d %d", &b, &e);
    aux = b;
    if(e == 0){
        b = 1;
        printf("%d", b);
    }else {
    for (int i = 1; i < e; i++)
    {
        b *= aux;
    }
    printf("%d", b);
}
    return 0;
}