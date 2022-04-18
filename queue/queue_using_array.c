#include <stdlib.h>
#include <stdio.h>



struct Queue {
    int size;
    int front;
    int rear;
    int *Q;
};


int isFull(struct Queue q)
{
    return q.rear == q.size - 1;
}

int isEmpty(struct Queue q)
{
    return q.front == q.rear;
}

void enqueue(struct Queue *q, int value)
{
    if (isFull(*q)) {
        printf("Queue is full");
    }
    else {
        q->rear++;
        q->Q[q->rear] = value;
    }

}

int dequeue(struct Queue *q)
{
    int x = -1;
    if (isEmpty(*q)) {
        printf("Queue is empty");
    }
    else {
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}

void display(struct Queue q)
{
    for (int i = q.front + 1; i <= q.rear; i++) {
        printf("%d ", q.Q[i]);
    }
    printf("\n");
}

void create(struct Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = -1;
    q->Q = (int *) malloc(q->size * sizeof(int));
}

int main(void)
{
    struct Queue q;
    create(&q, 5);

    enqueue(&q, 5);
    enqueue(&q, 7);
    enqueue(&q, 9);
    enqueue(&q, 10);
    int dequeued = dequeue(&q);
    printf("Dequed element is: %d", dequeued);
    display(q);
    return 0;
}