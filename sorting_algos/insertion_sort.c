#include <stdio.h>
#include "common.h"


void insertionSort(int A[], int size) {
    int i, j, x;
    for (i = 1; i < size; i++) {
        j = i - 1;
        x = A[i];
        while (j > -1 && A[j] > x) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = x;
    }
}

int main(void) {
    int A[] = {20, 13, 23, 11, 99, 3, 7, 1, 34, 48};
    int size = 9;
    insertionSort(A, size);
    display(A, size);
    return 0;
}