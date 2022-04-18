#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node *next;
} *top = NULL;

void push(int x)
{
    struct Node *t = malloc(sizeof(struct Node));
    if (t == NULL) {
        printf("Stack if full");
    }
    else {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int pop()
{
    int x = -1;
    if (top == NULL) {
        printf("Stack is empty");
    }
    else {
        struct Node *t;
        t = top;
        top = top -> next;
        x = t->data;
        free(t);
    }
    return x;
}

void display()
{
    struct Node *p;
    p = top;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main(void)
{
    push(10);
    push(20);
    push(20);
    display();
    return 0;
}