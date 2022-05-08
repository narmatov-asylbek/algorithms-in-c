#include "common.h"
#include <limits.h>



int partition(int A[], int l, int h) {
    int pivot = A[l];
    int i = l, j = h;

    do {
        do {i++;} while (A[i] <= pivot);
        do {j--;} while(A[j] >= pivot);

        if (i < j) { swap(&A[i], &A[j]); }
    } while (i < j) ;

    swap(&A[l], &A[j]);
    return j;
}

void quickSort(int A[], int l, int h) {
    int j;
    if (l < h) {
        j = partition(A, l, h);
        quickSort(A, l, j);
        quickSort(A, j + 1, h);
    }
}


int main(void) {
    int A[] = {20, 13, 23, 11, 99, 3, 7, 1, 34, 48, INT_MAX};
    quickSort(A, 0, 10);
    display(A, 10);
    return 0;
}