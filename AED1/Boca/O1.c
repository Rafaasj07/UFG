#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void bitonicMerge(int arr[], int lowIndex, int count, int direction)
{
    if (count > 1)
    {
        int k = count / 2;
        for (int i = lowIndex; i < lowIndex + k; i++)
        {
            if ((direction == 1 && arr[i] > arr[i + k]) ||
                (direction == 0 && arr[i] < arr[i + k]))
            {
                swap(&arr[i], &arr[i + k]);
            }
        }
        bitonicMerge(arr, lowIndex, k, direction);
        bitonicMerge(arr, lowIndex + k, k, direction);
    }
}

void bitonicSort(int arr[], int lowIndex, int count, int direction)
{
    if (count > 1)
    {
        int k = count / 2;
        bitonicSort(arr, lowIndex, k, 1);
        bitonicSort(arr, lowIndex + k, k, 0);
        bitonicMerge(arr, lowIndex, count, direction);
    }
}

int nextPower(int n)
{
    int power = 1;
    while (power < n)
        power *= 2;
    return power;
}

int main()
{
    int n;
    scanf("%d", &n);

    int size = nextPower(n);
    int *arr = malloc(size * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (int i = n; i < size; i++)
    {
        arr[i] = INT_MAX;
    }

    bitonicSort(arr, 0, size, 1);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    free(arr);
    return 0;
}