#include <stdio.h>

#define MAX_SIZE 200000 

int binary_search(int arr[], int n, int target) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return 1;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else { 
            high = mid - 1;
        }
    }

    return 0;
}

int main() {
    int N, Q;

    if (scanf("%d %d", &N, &Q) != 2) {
        return 1;
    }

    int A[MAX_SIZE];
    for (int i = 0; i < N; i++) {
        if (scanf("%d", &A[i]) != 1) {
            return 1;
        }
    }

    int X;
    for (int i = 0; i < Q; i++) {
        if (scanf("%d", &X) != 1) {
            return 1;
        }

        int found = binary_search(A, N, X);

        printf("%d\n", found);
    }

    return 0;
}