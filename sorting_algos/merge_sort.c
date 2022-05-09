#include <stdlib.h>
#include "common.h"

void
merge(int arr[], int m, int l, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    // Create temp arrays
    int L[n1], R[n2];

    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    // Merge the temp arrays back into arr[l..r]

    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort_rec(int s[], int low, int high) {
    int middle;
    if (low < high) {
        middle = (low + high) / 2;
        merge_sort_rec(s, low, middle);
        merge_sort_rec(s, middle + 1, high);
        merge(s, middle, low, high);
    }
}

void merge_sort(int s[], int length) {
    merge_sort_rec(s, 0, length - 1);
}

int main(void) {
    int A[] = {20, 13, 23, 11, 99, 3, 7, 1, 34, 48, 19};
    merge_sort(A, 10);
    display(A, 10);
    return 0;
}