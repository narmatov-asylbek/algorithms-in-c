#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* Head;


void Create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    Head = (struct Node *)malloc(sizeof(struct Node));
    Head->data = A[0];
    Head->next = Head;
    last = Head;

    for (i = 1; i < n; i++) {
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}


void Display(struct Node* h)
{
    do {
        printf("Value of node: %d \n", h->data);
        h = h->next;
    } while(h != Head);
    printf("\n");

}

void DisplayRecursive(struct Node* h)
{
    static int flag = 0;
    if (h != Head || flag == 0) {
        flag = 1;
        printf("Node value is %d \n", h->data);
        DisplayRecursive(h->next);
    }
    flag = 0;
}

int Length(struct Node* h)
{
    int len = 0;
    do {
        len++;
        h = h->next;
    } while (h != Head);
    return len;
}

void Insert(struct Node* h, int index, int value)
{
    struct Node* t;
    int i;

    if (index <0 || index > Length(h)) { return; }

    t = (struct Node*)malloc(sizeof(struct Node));
    t->data = value;

    if (index == 0) {
        if (Head == NULL) {
            Head = t;
            Head->next = Head;
        }
        else {
            while (h->next != Head) { h = h->next; }
            h->next = t;
            t->next = Head;
            Head = t;
        }
    }
    else {
        for (i = 0; i < index - 1; i++) { h = h->next; }
        t->next = h->next;
        h->next = t;
    }
}


int Delete(struct Node *p, int index)
{
    struct Node *q;
    int i, x;

    if (index < 0 || index > Length(p)) { return -1; }

    if (index == 1) {
        while (p->next != Head) { p = p->next; }
        x = Head -> data;
        if (Head == p) {
            free(Head);
            Head = NULL;
        }
        else {
            p->next = Head->next;
            free(Head);
            Head = p->next;
        }
    }
    else {
        for (i = 0; i < index - 2; i++) { p = p->next; }
        q = p->next;
        p->next = q ->next;
        x = q->data;
        free(q);
    }
    return x;

}

int main(void)
{
    int A[] = {1, 2, 3, 4, 5, 6};
    Create(A, 6);
    DisplayRecursive(Head);

    return 0;
}

