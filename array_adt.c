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


// Get operation
int Get(struct Array array, int index)
{
    if (index > 0 && index < array.length) {
        return array.A[index];
    }
    return - 1;
}


// Set operation
void Set(struct Array* array, int index, int value)
{
    if (index > 0 && index < array->length) {
        array->A[index] = value;
    }
}

int Max(struct Array array)
{
    if (array.length == 0) { return - 1; }

    int max = array.A[0];
    for (int i = 0; i < array.length; i++) {
        if (array.A[i] > max) {
            max = array.A[i];
        }
    }
    return max;
}

int Min(struct Array array)
{
    if (array.length == 0) { return -1; }

    int min = array.A[0];
    for (int i = 0; i < array.length; i++) {
        if (array.A[i] < min) {
            min = array.A[i];
        }
    }
    return min;
}

int Sum(struct Array array)
{
    int sum = 0;
    for (int index = 0; index < array.length; index++) {
        sum = sum + array.A[index];
    }
    return sum;
}

float Avg(struct Array array)
{
    return (float) (Sum(array) / array.length);
}

void Reverse(struct Array* array)
{
    int i; int j;
    for (i = 0, j = array->length; i < j; i++, j--) {
        int temp = array->A[i];
        array->A[i] = array->A[j];
        array->A[j] = temp;
    }
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