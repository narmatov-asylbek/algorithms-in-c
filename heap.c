#include <stdio.h>
#include <stdlib.h>


void insert(int H[], int index)
{
    int i = index, temp;
    temp = H[i];
    while (i > 1 && temp > H[i/2]) {
        H[i] = H[i/2];
        i = i / 2;
    }
    H[i] = temp;
}

int delete(int A[], int size)
{
    int i, j, x, val;
    x = A[size];
    val = A[1];
    A[1] = A[size];
    A[size] = val;
    i = 1; j = i * 2;

    while (j < size - 1)
    {
        if (A[j + 1] > A[j]) {
            j = j + 1;
        }
        if (A[i] < A[j]) {
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i = j;
            j = 2 * j;
        }
        else {
            break;
        }
    }
    return val;
}

int main(void) {
    int H[] = {0, 2, 5, 8, 9, 4, 10, 7};
    insert(H, 2);
    insert(H, 3);
    insert(H, 4);
    insert(H, 5);
    insert(H, 6);
    insert(H, 7);
    return 0;
}