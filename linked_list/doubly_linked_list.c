#include <stdio.h>
#include <stdlib.h>


struct Node {
    struct Node *prev;
    int data;
    struct Node *next;
};

struct Node *first = NULL;

void Create(int A[], int size)
{
    struct Node *t, *last;
    int i;

    first = (struct Node *) malloc(sizeof(struct Node));
    first->data = A[0];
    first->prev = first->next = NULL;
    last = first;

    for (i = 0; i < size; i++) {
        t = (struct Node *) malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = last->next;
        t->prev = last;
        last->next = t;
        last = t;
    }
}

void Display(struct Node *p)
{
    while(p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int Length(struct Node* p)
{
    int len = 0;
    while (p) {
        len++;
        p = p->next;
    }
    return len;
}

void Insert(struct Node *p, int index, int x)
{
    if (index < 0 || index > Length(p)) { return; }
    struct Node *t = (struct Node*) malloc(sizeof(struct Node));
    t->data = x;
    int i;

    if (index == 0) {
        t->prev = NULL;
        t->next = first;
        first->prev = t;
        first = t;
    }
    else {
        for (i = 0; i < index - 1; i++) { p = p->next; }
        t->prev = p;
        t->next = p->next;
        if (p->next) {
            p->next->prev = t;
        }
        p->next = t;
    }

}

int Delete(struct Node *p, int index)
{
    if (index < 1 || index > Length(p)) { return - 1; }
    int x, i;

    if (index == 1) {
        first = first -> next;
        if (first) {first->prev = NULL;}
        x = p->data;
        free(p);
    }
    else {
        for (i = 0; i < index - 1; i++) { p = p->next; }
        p->prev->next = p->next;
        if (p->next) {
            p->next->prev = p->prev;
        }
        x = p->data;
        free(p);
    }
    return x;
}

int main(void)
{
    int A[] = {1, 2, 3, 4, 5};
    Create(A, 4);
    printf("\nLength is %d \n", Length(first));
    Display(first);
    return 0;
}