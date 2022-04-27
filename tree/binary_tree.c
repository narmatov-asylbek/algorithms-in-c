#include <stdio.h>
#include <stdlib.h>


typedef struct treeNode {
    int value;
    struct treeNode *left;
    struct treeNode *right;
} treeNode;


treeNode *createNode(int value) {
    treeNode *result = malloc(sizeof(treeNode));
    if (result != NULL) {
        result->left = result->right = NULL;
        result->value = value;
    }
    return result;
}

void printTabs(int numTabs) {
    for (int i = 0; i < numTabs; i++) {
        printf("\t");
    }
}

void printTree(treeNode *root, int level) {
    if (root == NULL) {
        printTabs(level);
        return;
    }
    printTabs(level);
    printf("value = %d\n", root->value);

    printf("left\n");
    printTree(root->left, level+1);
    printTabs(level);

    printf("right\n");
    printTree(root->right, level + 1);
    printTabs(level);

}

int main(void)
{
    treeNode *n1 = createNode(1);
    treeNode *n2 = createNode(2);
    treeNode *n3 = createNode(3);
    treeNode *n4 = createNode(4);
    treeNode *n5 = createNode(5);

    n1->left = n2;
    n1->right = n3;
    n3->left = n4;
    n3->right = n5;
    printTree(n1, 0);


    free(n1);
    free(n2);
    free(n3);
    free(n4);
    free(n5);
    return 0;
}