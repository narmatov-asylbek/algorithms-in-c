#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


struct Node *root=NULL;

void Treecreate()
{
    struct Node *p,*t;
    int x;
    struct Queue q;
    create(&q,8);
    printf("Eneter root value ");
    scanf("%d",&x);
    root=(struct Node *)malloc(sizeof(struct Node));
    root->data=x;
    root->lchild=root->rchild=NULL;
    enqueue(&q,root);
    while(!isEmpty(q))
    {
        p=dequeue(&q);
        printf("eneter left child of %d ",p->data);
        scanf("%d",&x);
        if(x!=-1)
        {
            t=(struct Node *)malloc(sizeof(struct
                    Node));
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            enqueue(&q,t);
        }
        printf("eneter right child of %d ",p->data);
        scanf("%d",&x);if(x!=-1)
        {
            t=(struct Node *)malloc(sizeof(struct
                    Node));
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->rchild=t;
            enqueue(&q,t);
        }
    }
}

void inOrderTraversal(struct Node *root)
{
    if (root == NULL) { return; }
    inOrderTraversal(root->lchild);
    printf("value = %d\n", root->data);
    inOrderTraversal(root->rchild);
}

void postOrderTraversal(struct Node *root)
{
    if (root == NULL) { return; }
    inOrderTraversal(root->lchild);
    inOrderTraversal(root->rchild);
    printf("value = %d\n", root->data);

}

void preOrderTraversal(struct Node *root)
{
    if (root == NULL) { return; }
    printf("value = %d\n", root->data);
    inOrderTraversal(root->lchild);
    inOrderTraversal(root->rchild);
}

int main(void)
{
    Treecreate();
    preOrderTraversal(root);
    return 0;
}