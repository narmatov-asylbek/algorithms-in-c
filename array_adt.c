#include <stdio.h>
#include <stdlib.h>


struct Array {
    int *A;
    int size;
    int length;
};

void Display(struct Array arr)
{
    printf("Elements are: ");
    for (int i = 0; i < arr.length; i++) {
        printf("%d ", arr.A[i]);
    }
    printf("\n");
}

void swap(int* a, int*b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

// Линейный Поиск. Сложность: O(N) по времени
int linearSearch(struct Array arr, int key)
{
    int i;
    for (i = 0; i < arr.length; i++) {
        if (arr.A[i] == key) {
            return i;
        }
    }
    return -1;
}


// Бинарный поиск
int binarySearch(struct Array arr, int key)
{
    int left, right, mid;
    left = 0; right = arr.length - 1;
    while (left <= right){
        mid = (right + left) / 2;
        if (arr.A[mid] == key) { return mid; }
        if (arr.A[mid] < key) { right--; }
        else { left++; }
    }
    return -1;
}

int main(void)
{
    struct Array array;
    int n, i;
    printf("Enter the size of an array: ");
    scanf("%d", &array.size);
    array.A = (int *) (malloc(array.size * sizeof(int)));
    array.length = 0;

    printf("Enter number of numbers: ");
    scanf("%d", &n);

    printf("Enter all elements \n");
    for (i = 0; i < n; i++) {
        scanf("%d", &array.A[i]);
    }
    array.length = n;
    Display(array);
    return 0;
}