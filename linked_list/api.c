#include <stdio.h>
#include <stdlib.h>


#define INT32_MIN -2147483648;

struct Node {
    int data;
    struct Node* next;
} *first=NULL;


// Helper Functions
struct Node* createNode(int n)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = n;
    temp->next = NULL;
    return temp;
}

void create(int A[], int size)
{
    if (size == 0) { return; }
    struct Node *last, *t;

    first = createNode(A[0]);
    last = first;

    for (int i = 0; i < size; i++) {
        t = createNode(A[i]);
        last->next = t;
        last = t;
    }
}


// API of Linked List
void display(struct Node*);
void displayRecursive(struct Node*);

int countNodes(struct Node*);
int countNodesRecursive(struct Node*);

int sum(struct Node*);
int sumRecursive(struct Node*);

int Max(struct Node*);
int MaxRecursive(struct Node*);

struct Node* search(struct Node*, int target);
struct Node*  searchRecursive(struct Node*, int target);

// Implementations
void display(struct Node* node)
{
    while (node) {
        printf("Node value: %d \n", node->data);
        node = node->next;
    }
}

void displayRecursive(struct Node* node) {
    if (node) {
        printf("Node value is %d \n", node->data);
        displayRecursive(node->next);
    }
}


int countNodes(struct Node* node)
{
    int counter = 0;
    while(node) {
        counter++;
        node = node->next;
    }
    return counter;
}

int countNodesRecursive(struct Node* node)
{
    if (!node) {
        return 0;
    }
    else {
        return countNodesRecursive(node->next) + 1;
    }
}

int sum(struct Node* node)
{
    int sum = 0;
    while (node) {
        sum += node->data;
        node = node->next;
    }
    return sum;
}

int sumRecursive(struct Node* node)
{
    if (node) {
        return sumRecursive(node->next) + node->data;
    }
    return 0;
}

int Max(struct Node* node) {
    int max = INT32_MIN;
    while (node) {
        if (node->data > max) {
            max = node->data;
        }
        node = node->next;
    }
    return max;
}

int MaxRecursive(struct Node* node)
{
    int x = 0;
    if (!node) {
        return INT32_MIN;
    }
    x = MaxRecursive(node->next);
    if (node->data > x) {
        return node->data;
    }
    return x;
}


struct Node* search(struct Node* node, int target)
{
    while (node) {
        if (node->data == target) {
            return node;
        }
        node = node -> next;
    }
    return NULL;
}


struct Node* searchRecursive(struct Node* node, int target)
{
    if (node) {
        if (node->data == target) {
            return node;
        }
        return searchRecursive(node->next, target);
    }
    return NULL;
}

void insert(struct Node* p, int index, int value)
{
    int i;
    if (index < 0 || index > countNodes(p)) { return; }
    struct Node* t = (struct Node*)malloc(sizeof(struct Node));
    t->data = value;

    if (index == 0) {
        t->next = first;
        first = t;
    }
    for (i = 0; i < index - 1; i++) {
        p = p->next;
    }
    t->next = p->next;
    p->next = t;

}

void insertSorted(struct Node* p, int x)
{
    struct Node *t, *q = NULL;
    t = (struct Node*)malloc(sizeof(struct Node));
    t->next = NULL;
    t->data = x;

    if (first == NULL) {
        first = t;
    }
    else {
        while (p && p->data < x) {
            q = p;
            p = p->next;
        }
        if (p == first) {
            t->next = first;
            first = t;
        }
        else {
            t->next = q->next;
            q->next = t;
        }
    }
}

int main(void)
{
    int A[] = {1, 2, 400, 4, 5};
    create(A, 5);
    display(first);

    int max = MaxRecursive(first);
    printf("Max elements is %d \n", max);

    insert(first, 5, 100);
    display(first);


    return 0;
}
