#include <stdio.h>

int main (void){
    int a;
    scanf("%d", &a);
    if(a > 0){
        int triangular = 0;
        for (int i = 1; i <= a; i++)
        {
            if (i * (i+1) * (i+2) == a){
                triangular = 1;
               break;
            }
        }   
            if (triangular == 1){
                printf("%d eh triangular \n", a);
            }else if(triangular == 0){
                printf("%d nao eh triangular \n", a);
            }
        return 0;
    }
}