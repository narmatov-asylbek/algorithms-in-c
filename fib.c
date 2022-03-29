#include <stdio.h>

int fib(int n)
{
    if (n <= 1) {
        return n;
    }
    return fib(n -2 ) + fib(n - 1);
}

// Fibonacci using recursion
int F[10];

int fib_memo(int n) {
    if (n <= 1) {
        F[n] = n;
        return F[n];
    }
    else {
        if (F[n - 2] == -1) { F[n-2] = fib_memo(n - 2); }
        if (F[n - 1] == -1) {F[n - 1] = fib_memo(n - 1); }
        return F[n - 2] + F[n - 1];
    }
}

int main(void)
{
    for (int i = 0; i < 10; i++) {
        F[i] = -1;
    }
    int result = fib_memo(8);
    printf("%d \n", result);
    return 0;
}