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
#endif