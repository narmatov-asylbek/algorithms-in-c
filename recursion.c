#include <stdio.h>


// Recursion with static variables
int fun(int n){
    static int x = 0;
    if (n > 0) {
        x--;
        return fun(n-1) + x;
    }
    return 0;
}


// Tree recursion
void tree_recursion(int n) {
    if (n > 0) {
        printf("%d \n", n);
        tree_recursion(n - 1);
        tree_recursion(n - 1);
    }
}

// Sum of n natural numbers using recursion
int sum_of_n(int n)
{
    if (n > 0) {
        return n + sum_of_n(n-1);
    }
    return 0;
}

int factorial(int n)
{
    if (n > 0) {
        return n * (n - 1);
    }
    return 1;
}
