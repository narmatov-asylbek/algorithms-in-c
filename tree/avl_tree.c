#include <stdlib.h>
#include <stdio.h>

struct Node {
    struct Node *left;
    int data;
    int height;
    struct Node *right;
} *root = NULL;

int nodeHeight(struct Node *p)
{
    int hl, hr;
    hl = p && p->left?p->left->height:0;
    hr = p && p->right?p->right->height:0;
    return hl > hr ? hl + 1: hr + 1;
}

int balanceFactor(struct Node *p)
{
    int hl, hr;
    hl = p && p->left?p->left->height:0;
    hr = p && p->right?p->right->height:0;
    return hl - hr;
}

struct Node *llRotation(struct Node *p)
{
    struct Node *pl = p->left;
    struct Node *plr = p->right;

    pl->right = p;
    p->left = plr;
    p->height = nodeHeight(p);
    pl->height = nodeHeight(pl);

    if (p == root) {
        root = pl;
    }
    return pl;
}

struct Node *lrRotation(struct Node *p){
    return NULL;
}

struct Node *rrRotation(struct Node *p){
    return NULL;
}

struct Node *rlRotation(struct Node *p){
    return NULL;
}

struct Node *insertRecursive(struct Node *p, int key)
{
    if (p == NULL) {
        struct Node *t = (struct Node *) malloc(sizeof(struct Node));
        t->data = key;
        t->height = 1;
        t->left = t->right = NULL;
        return t;
    }
    else if (key < p->data) {
        p->left = insertRecursive(p->left, key);
    } else if (key > p->data){
        p->right = insertRecursive(p->right, key);
    }
    p->height = nodeHeight(p);
    if (balanceFactor(p) == 2 && balanceFactor(p->left) == 1) {
        return llRotation(p);
    }
    else if (balanceFactor(p) == 2 && balanceFactor(p->left) == -1) {
        return lrRotation(p);
    }
    else if (balanceFactor(p) == -22 && balanceFactor(p->right) == -1) {
        return rrRotation(p);
    }
    else if (balanceFactor(p) == -2 && balanceFactor(p->right) == 1) {
        return rlRotation(p);
    }
    return p;
}


int main(void)
{
    insertRecursive(root, 10);
    insertRecursive(root, 5);
    insertRecursive(root, 2);
    return 0;
}