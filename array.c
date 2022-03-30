#include <stdio.h>
#include <stdlib.h>

// Докажем что array занимает непрерывные блоки памяти
void cont(void)
{
    int A[5];
    for (int i = 0; i < 5; i++) {
        printf("%p \n", &A[i]);
    }
}


// Resizing array
void dynamic_array(void)
{
    int *p, *q;
    p = (int *)malloc(5 * sizeof(int));
    p[0] = 1; p[1] = 2; p[2] = 3; p[3] = 4; p[4] = 5;
    q = (int *) malloc(10 * sizeof(int));

    for (int i = 0; i < 5; i++) {
        q[i] = p[i];
    }
    free(p);
    p = q;
    q = NULL;

    for (int i = 0; i < 10; i++) {
        printf("%d \n", p[i]);
    }
}

int main(void) {
    cont();
    printf("Dynamic array \n");
    dynamic_array();
    return 0;
}
