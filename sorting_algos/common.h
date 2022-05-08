#include <stdio.h>


#ifndef common
#define common

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b =temp;
}

void display(int A[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int intCompare(int *first, int *second) {
    if (*first > *second) { return 1; }
    if (*first < *second) { return -1; }
    return 0;
}
#endif