#include "common.h"



int partition(int s[], int left, int right) {
    int pivot, pos, i;
    pivot = right;
    pos = left;

    for (i = left; i < right; i++) {
        if (s[i] < s[pivot]) {
            swap(&s[i], &s[pos]);
            pos++;
        }
    }
    swap(&s[pivot], &s[pos]);
    return pos;
}

void quickSort(int s[], int left, int right) {
    int p;
    if (left < right) {
        p = partition(s, left, right);
        quickSort(s, left, p - 1);
        quickSort(s, p + 1, right);
    }
}

int main(void) {
    int A[] = {20, 13, 23, 11, 99, 3, 7, 1, 34, 48, 33};
    quickSort(A, 0, 10);
    display(A, 10);
    return 0;
}