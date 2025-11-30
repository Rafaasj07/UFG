#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (abs(i - j) <= 1)
            {
                int k = 2 * i + j;
                printf("O elemento M(%d)(%d) no vetor eh %d\n", i, j, k);
            }

    return 0;
}