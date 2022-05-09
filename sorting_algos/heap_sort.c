#include <stdio.h>
#include "common.h"

#define PQ_SIZE 100

// There is a bug. And I cannot figure out, why this program sorts incorrectly

typedef struct {
    int q[PQ_SIZE + 1];
    int n;
} priority_queue;


int pq_parent(int n) {
    if (n == 1) { return -1; }
    return (int)(n/2);
}

int pq_young_child(int n) {
    return (2 * n);
}

void pq_swap(int A[], int p, int x) {
    int temp = A[p];
    A[p] = A[x];
    A[x] = temp;
}

void bubble_up(priority_queue *q, int p) {
    if (pq_parent(p) == -1) { return; }
    if (q->q[pq_parent(p)] > q->q[p]) {
        pq_swap(q->q, p, pq_parent(p));
        bubble_up(q, pq_parent(p));
    }
}

void pq_insert(priority_queue *q, int x) {
    if (q->n >= PQ_SIZE) {
        printf("Priority Queue overflow\n");
        return;
    }
    q->n = (q->n) + 1;
    q->q[q->n] = x;
    bubble_up(q, q->n);
}

void pq_init(priority_queue *q) {
    q->n = 0;
}

void make_heap(priority_queue *q, int s[], int n) {
    int i;
    pq_init(q);
    for (i = 0; i < n; i++) {
        pq_insert(q, s[i]);
    }
}

void bubble_down(priority_queue *q, int p) {
    int c = pq_young_child(p), i, min_index = p;
    for (i = 0; i <= 1; i++) {
        if ((c + 1) <= q->n) {
            if (q->q[min_index] > q->q[c+i]) { min_index = c + i; }
        }
    }
    if (min_index != p) {
        pq_swap(q->q, p, min_index);
        bubble_down(q, min_index);
    }
}

int extract_min(priority_queue *q) {
    int min = -1;
    if (q->n <= 0) {
        printf("Empty Priority Queue\n");
        return min;
    }
    min = q->q[1];
    q->q[1] = q->q[q->n];
    q->n = q->n - 1;
    bubble_down(q, 1);
    return min;
}

void heap_sort(int s[], int n) {
    int i;
    priority_queue q;
    make_heap(&q, s, n);
    for (i = 0; i < n - 1; i++) {
        s[i] = extract_min(&q);
    }
}

int main(void) {
    int A[] = {20, 13, 23, 11, 99, 3, 7, 1, 34, 48};
    heap_sort(A, 9);
    display(A, 9);
    return 0;
}