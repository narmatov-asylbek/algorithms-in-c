#include "common.h"


void selectionSort(int A[], int size) {
    int i, k, j;
    for (i = 0; i < size - 1; i++) {
        for (j = k = i; j < size - 1; j++) {
            if (A[j] < A[k]) {
                k = j;
            }
        }
        swap(&A[i], &A[k]);
    }
}

int main(void) {
    int A[] = {20, 13, 23, 11, 99, 3, 7, 1, 34, 48};
    int size = 9;
    selectionSort(A, size);
    display(A, size);
    return 0;
}