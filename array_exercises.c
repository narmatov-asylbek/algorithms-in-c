#include <stdlib.h>
#include <stdio.h>


struct Array {
    int *A;
    int size;
    int length;
};


int findSingleMissing(struct Array array) {
    int diff = array.A[0] - 0;
    for (int i = 0; i < array.length; i++) {
        if (array.A[i] - i != diff) {
            return diff + i;
        }
    }
    return -1;
}

void minAndMaxInOnePass(struct Array array)
{
    int min, max;
    min = max = array.A[0];

    for (int i = 1; i < array.length; i++) {
        if (array.A[i] > max) {
            max = array.A[i];
        }
        if (array.A[i] < min) {
            min = array.A[i];
        }
    }
    printf("Min: %d, Max: %d \n", min, max);
}


int findDuplicatesInSortedArray(struct Array array)
{
    int last_duplicate = 0;
    for (int i = 1; i < array.length; i++) {
        if(array.A[i] == array.A[i - 1] && array.A[i] != last_duplicate) {
            last_duplicate = array.A[i];
        }
    }
    return last_duplicate;
}

int main(void)
{
    struct Array array = {.size=20, .length=8};
    array.A = (int *)malloc(sizeof(int) * array.length);
    array.A[0] = 0; array.A[1] = 1; array.A[2] = 2; array.A[3] = 3;
    array.A[4] = 4; array.A[5] = 6; array.A[6] = 7;
    minAndMaxInOnePass(array);
    int missing = findSingleMissing(array);
    printf("Missing %d \n", missing);
}