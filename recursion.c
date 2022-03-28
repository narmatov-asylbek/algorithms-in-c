#include <stdio.h>


int fib(int n)
{
    if (n <= 2) {
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}

int main(void)
{
    int result = fib(20);
    printf("%d\n", result);
}