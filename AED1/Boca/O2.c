#include <stdio.h>
#include <stdlib.h>

#define MAX 200000

int main() 
{
    int n, x;
    scanf("%d", &n);
    
    int *cont = (int*)calloc(MAX + 1, sizeof(int));
    
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &x);
        cont[x]++;
    }

    for (int i = 0; i <= MAX; i++) 
    {
        while (cont[i]--) 
        {
            printf("%d ", i);
        }
    }

    free(cont);
    return 0;
}
