#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    struct Node *left;
    int data;
    struct Node *right;
} Node;

Node *root = NULL;

void insert(int key)
{
    Node *t = root;
    Node *r, *p;

    p = (Node *)malloc(sizeof(Node));
    p->data = key;
    p->right = p->left = NULL;

    if (root == NULL)
    {
        root = p;
        return;
    }
    while (t) {
        r = t;
        if (key < t->data) { t = t-> left; }
        else if (key > t->data) { t = t-> right; }
        else { return; }
    }
    if (key < r->data) {
        r->left = p;
    }
    else {
        r -> right = p;
    }
}

void inOrder(Node *p)
{
    if (p)
    {
        inOrder(p->left);
        printf(" %d ", p->data);
        inOrder(p->right);
    }
}

Node *search(Node *p, int key)
{
    Node *temp = p;
    while (temp)
    {
        if (temp->data == key) {
            return temp;
        }
        else if (temp->data > key) {
            temp = temp -> left;
        }
        else {
            temp = temp -> right;
        }
    }
    return NULL;
}

Node *searchRecursive(Node *p, int key)
{
    if (p == NULL) {
        return NULL;
    } else if (p->data > key) {
        return searchRecursive(p->left, key);
    } else {
        return searchRecursive(p->right, key);
    }
}

Node *insertRecursive(Node *p, int key)
{
    if (p == NULL) {
        Node *t = (Node *) malloc(sizeof(Node));
        t->data = key;
        t->left = t->right = NULL;
        return t;
    }
    else if (key < p->data) {
        p->left = insertRecursive(p->left, key);
    } else if (key > p->data){
        p->right = insertRecursive(p->right, key);
    }
    return p;
}

int height(Node *p) {
    if (p == NULL) { return 0; }
    int x = height(p->left);
    int y = height(p->right);
    if (x > y) { return x + 1; }
    else { return y + 1; }
}

Node *inPre(Node *p)
{
    while (p && p->right != NULL) {
        p = p->right;
    }
    return p;
}

Node *inSucc(Node *p)
{
    while (p && p->left != NULL) {
        p = p->left;
    }
    return p;
}

Node *delete(Node *p, int key)
{
    Node *q;
    if (p == NULL) { return NULL; }
    if (p->left == NULL && p->right == NULL) {
        if (p == root) {
            root = NULL;
        }
        free(p);
        return NULL;
    }
    if (key < p -> data) {
        p->left = delete(p->left, key);
    }
    else if (key > p->data) {
        p->right = delete(p->right, key);
    }
    else {
        if (height(p->left) > height(p->right)) {
            q = inPre(p->left);
            p->data = q-> data;
            p->left = delete(p->left, q->data);
        }
        else {
            q = inSucc(p->right);
            p->data = q-> data;
            p->left = delete(p->left, q->data);
        }
    }
}


int main(void) {
    insert(10);
    insert(5);
    insert(20);
    insert(8);
    insert(30);
    delete(root, 30);
    inOrder(root);
    printf("\n");
    return 0;
}
