#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int item;
    tree* parent; // Указатель на родительский узел
    tree* left; // Указатель на левый дочерний узел
    tree* right; // Указатель на правый дочерний элемент
} tree;



tree* search(tree* t, int target)
{
    if (t == NULL) { return NULL; }
    if (t->item == target) { return t; }
    if (t->item < target) {
        return search(t->right, target);
    }
    else {
        return search(t->left, target);
    }
}

tree* min(tree* t)
{
    tree* min;
    if (t == NULL) { return NULL; }
    min = t;
    while (min->left != NULL) {
        min = min->left;
    }
    return min;
}

tree* max(tree* t)
{
    tree* max;
    if (t == NULL) { return NULL; }
    max = t;
    while (max->right != NULL) {
        max = max->right;
    }
    return max;
}

void traverse_tree(tree* t)
{
    if (t != NULL) {
        traverse_tree(t->left);
        printf("%d", t->item);
        traverse_tree(t->right);
    }
}

void insert_tree(tree** t, tree* parent, int x)
{
    tree* p;
    if (*t == NULL) {
        p = malloc(sizeof(tree));
        p->item = x;
        p->left = p->right = NULL;
        p->parent = parent;
        *t = p;
        return;
    }
    if (x > (*t)->item) {
        insert_tree((*t)->right, parent, x);
    }
    else {
        insert_tree((*t)->left, parent, x);
    }
}
