#include "common.h"

void bubbleSort(int A[], int size) {
    int swapped;
    for (int i = 0; i < size - 1; i++) {
        swapped = 0;
        for (int j = 0; j < size - 1 - i; j++) {
            if (A[j] > A[j + 1]) {
                swap(&A[j], &A[j + 1]);
                swapped = 1;
            }
        }
        if (swapped == 0) { return; }
    }
}



int main(void) {
    int A[] = {20, 13, 23, 11, 99, 3, 7, 1, 34, 48};
    int size = 9;
    bubbleSort(A, size);
    display(A, size);
    return 0;
}