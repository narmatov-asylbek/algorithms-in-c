#include <stdio.h>
#include <stdlib.h>

typedef struct listNode {
    struct ListNode *prev;
    struct ListNode *next;
    void *value;
} listNode;


typedef struct listIter {
    listNode *next;
    int direction;
} listIter;


typedef struct list {
    listNode *head;
    listNode *tail;
    unsigned int len;
} list;
