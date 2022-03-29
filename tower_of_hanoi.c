#include <stdio.h>


void tower(int n, int A, int B, int C)
{
    if (n > 0)
    {
        tower(n-1, A, C, B);
        printf("(%d, %d) \n", A, C);
        tower(n-1, B, A, C);
    }
}

int main(void)
{
    tower(2, 1, 2, 3);
    return 0;
}